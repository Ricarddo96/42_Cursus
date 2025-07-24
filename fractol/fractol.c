/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:31:49 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/24 19:30:58 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int handle_keypress(int keysym, void *d)
{
	t_data *data;
	int boolean;
	 
	data = (t_data *)d;
	boolean = 0;
	if ( keysym == KEY_UP || keysym == KEY_DOWN || keysym == KEY_RIGHT || keysym == KEY_LEFT)
		boolean = 1;
	if (keysym == KEY_UP)
		data->offset_y -= 0.1 / data->zoom;
	else if (keysym == KEY_DOWN)
		data->offset_y += 0.1 / data->zoom;
	else if (keysym == KEY_RIGHT)
		data->offset_x += 0.1 / data->zoom;
	else if (keysym == KEY_LEFT)
		data->offset_x -= 0.1 / data->zoom;
	if (keysym == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		exit(EXIT_SUCCESS); 
	}
	if (boolean == 1)
		render_fractal(data);
	return (0);
}
int handle_destroy(void *d)
{
	t_data *data;
	
	data = (t_data *)d;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}

void parse_arguments(int c, char **v, t_data *data)
{
	if (c < 2 || c > 4)
		print_help();
	if (ft_strncmp(v[1], "mandelbrot", ft_strlen("mandelbrot") + 1) == 0)
	{
		if (c != 2)
			print_help();
		data->fractal_type = MANDELBROT;
	}
	else if (ft_strncmp(v[1], "julia", ft_strlen("julia") + 1) == 0)
	{
		if (c != 4)
			print_help();
		data->julia_c_r = ft_atof(v[2]);
		data->julia_c_i = ft_atof(v[3]);
		data->fractal_type = JULIA;
	}
	else 
		print_help();
}

int get_color(int iterations, int max_iterations)
{
	int binary_ARGB;
	
    if (iterations == max_iterations)
        return (0x000000);
    int r = (iterations * 3) % 256;
    int g = (iterations * 8) % 256;
    int b = (iterations * 10) % 256;
	binary_ARGB = ((r << 16) | (g << 8) | b);
    return (binary_ARGB);
}
/* 
int get_color(int iterations, int max_iterations)
{
    if (iterations == max_iterations)
        return (0x000000);
    double frequency = 0.1; 
    double phase_r = 0.0;
    double phase_g = 2.0;
    double phase_b = 6.0;
    int r = (int)(sin(frequency * iterations + phase_r) * 127 + 128);
    int g = (int)(sin(frequency * iterations + phase_g) * 127 + 128);
    int b = (int)(sin(frequency * iterations + phase_b) * 127 + 128);
    if (r < 0) 
		r = 0; 
	if (r > 255) 
		r = 255;
    if (g < 0) 
		g = 0; 
	if (g > 255) 
		g = 255;
    if (b < 0) 
		b = 0; 
	if (b > 255) 
		b = 255;
    return ((r << 16) | (g << 8) | b);
} */
void put_pixel(t_img *img, int x, int y, int color)
{
	char *pxl;

	pxl = img->addr + (y * (img->line_len) + x * (img->bpp / 8));
	*(unsigned int *)pxl = color;
}
int mouse_hook(int button, int x, int y, t_data *d)
{
	double	mouse_r;
	double	mouse_i;
	
	mouse_r = d->offset_x + ((x / (double)WIDTH * 3.0) - 2.0) / d->zoom;
	mouse_i = d->offset_y + ((y / (double)HEIGHT * 3.0) - 1.5) / d->zoom; 
	if (button == SCROLL_UP)
		d->zoom *= 1.1;
	if (button == SCROLL_DOWN)
		d->zoom /= 1.1;
	d->offset_x = mouse_r - ((x / (double)WIDTH * 3.0) - 2.0) / d->zoom;
	d->offset_y = mouse_i - ((y / (double)HEIGHT * 3.0) - 1.5) / d->zoom;
	render_fractal(d);
	return (0);
}
void render_fractal(t_data *d)
{
	int x_px;
	int y_px;
	int iterations;

	y_px = 0;
	while (y_px < HEIGHT)
	{
		x_px = 0;
		while (x_px < WIDTH)
		{
			if (d->fractal_type == MANDELBROT)
			{
				d->c_real = d->offset_x + ((x_px / (double)WIDTH * 3.0) - 2.0) / d->zoom;
				d->c_imag = d->offset_y + ((y_px / (double)HEIGHT * 3.0) - 1.5) / d->zoom;
				d->z_real = 0.0;
				d->z_imag = 0.0;
			}
			else if (d->fractal_type == JULIA)
			{
				d->c_real = d->julia_c_r;
				d->c_imag = d->julia_c_i;
				d->z_real = d->offset_x + ((x_px / (double)WIDTH * 3.0) - 2.0) / d->zoom;
				d->z_imag = d->offset_y + ((y_px / (double)HEIGHT * 3.0) - 1.5) / d->zoom;
			}
			iterations = 0;
			while ((d->z_real * d->z_real + d->z_imag * d->z_imag < 4) && (iterations < d->max_iter))
			{
				d->z_r_tmp = (d->z_real * d->z_real) - (d->z_imag * d->z_imag) + d->c_real;
				d->z_imag = (2.0 * d->z_real * d->z_imag) + d->c_imag; 
				d->z_real = d->z_r_tmp;
				iterations++;
			}
			put_pixel(&d->img, x_px, y_px, get_color(iterations, d->max_iter));
			x_px++;
		}
		y_px++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.img_ptr, 0, 0);
}

int main(int argc, char **argv)
{
	t_data data;
	

	data.max_iter = 350;   
    data.zoom = 1.0;
    data.offset_x = 0.0;
	data.offset_y = 0.0;
	
	parse_arguments(argc, argv, &data);
	
	data.mlx_ptr = mlx_init();
	
	if (data.mlx_ptr == NULL)
		ft_error("Initialization error", EXIT_FAILURE);	
		
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "fractol");
	
	if (data.win_ptr == NULL)
		ft_error("Failed to create window", EXIT_FAILURE);
		
		
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	/* if (data.img.img_ptr == NULL)
	{
			//liberar y acabar (poner el free en el return (?)) 
	} */
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp, 
			&data.img.line_len, &data.img.endian);
	/*if (data.img.addr == NULL)
	 {
			//liberar y acabar (poner el free en el return (?)) 
	} */
	render_fractal(&data);
	mlx_hook(data.win_ptr, 4, BUTTON_PRESS_MASK, mouse_hook, &data);
	mlx_hook(data.win_ptr, DESTROY_NOTIFY, 0, handle_destroy, &data);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}	