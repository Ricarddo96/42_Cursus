/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:31:49 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/22 19:46:15 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int handle_keypress(int keysym, void *d)
{
	t_data *data;
	 
	data = (t_data *)d;
	if (keysym == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		exit(EXIT_SUCCESS); 
	}
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
		//faltn atof para convertit ascii a flotante (devuelve double creo)
		//tambien faltan dos variables en data para almacenar los resultados de 
		//atof para el primer numero (real) y el segundo (imaginario) de julia;
		data->fractal_type = JULIA;
	}
	else 
		print_help();
}

int get_color(int iterations, int max_iterations)
{
    if (iterations == max_iterations)
        return (0x000000);

    
    int r = (iterations * 3) % 256;
    int g = (iterations * 8) % 256;
    int b = (iterations * 10) % 256;

    return ((r << 16) | (g << 8) | b);
}

void put_pixel(t_img *img, int x, int y, int color)
{
	char *pxl;

	pxl = img->addr + (y * (img->line_len) + x * (img->bpp / 8));
	*(unsigned int *)pxl = color;
}

void render_fractal(t_data *d)
{
	int		x_px;
	int		y_px;
	int		iterations;
	double	z_r_tmp;

	y_px = 0;
	while (y_px < HEIGHT)
	{
		x_px = 0;
		while (x_px < WIDTH)
		{
			d->c_r = (x_px / (double)WIDTH * 3.0) - 2.0;	 
			d->c_i = (y_px / (double)HEIGHT * 3.0) - 1.5;
			d->c_r = d->offset_x + d->c_r / d->zoom;
			d->c_i = d->offset_y + d->c_i / d->zoom;
			d->z_r = 0.0;
			d->z_i = 0.0;
			iterations = 0;
			while ((d->z_r * d->z_r+ d->z_i * d->z_i < 4) && (iterations < d->max_iter))
            {
                z_r_tmp = (d->z_r * d->z_r) - (d->z_i * d->z_i) + d->c_r;
                d->z_i = (2.0 * d->z_r * d->z_i) + d->c_i;
                d->z_r = z_r_tmp;
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
	

	data.max_iter = 50;   
    data.zoom = 1.0;
    data.offset_x = 0.0;
	data.offset_y = 0.0;
	
	parse_arguments(argc, argv, &data);
	
	data.mlx_ptr = mlx_init();
	
	if (data.mlx_ptr == NULL)
		ft_error("Initialization error", EXIT_FAILURE);	
		
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 800, "fractol");
	
	if (data.win_ptr == NULL)
		ft_error("Failed to create window", EXIT_FAILURE);
		
		
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, 800, 800);
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
	if (data.fractal_type == MANDELBROT)
		render_fractal(&data);
	mlx_hook(data.win_ptr, DESTROY_NOTIFY, 0, handle_destroy, &data);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}	