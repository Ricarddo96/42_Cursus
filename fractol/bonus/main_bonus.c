/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:31:49 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/26 19:13:32 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	cleanup(t_data *data)
{
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	ft_error(char *msg, int code, t_data *data)
{
	ssize_t	a;

	cleanup(data);
	a = write(2, "Error: ", 7);
	(void)a;
	a = write(2, msg, ft_strlen(msg));
	(void)a;
	a = write(2, "\n", 1);
	(void)a;
	exit(code);
}

void	print_help(void)
{
	ssize_t	a;

	a = write(1, "\nUsage: ./fractol <fractal_name> ", 33);
	(void)a;
	a = write(1, "[optional_julia_parameters]\n\nAvailable fractals:\n\n", 51);
	(void)a;
	a = write(1, "  mandelbrot\n", 14);
	(void)a;
	a = write(1, "  julia <real_value> <imaginary_value>\n", 40);
	(void)a;
	a = write(1, "  burning\n\n", 12);
	(void)a;
	a = write(1, "Examples:\n\n", 11);
	(void)a;
	a = write(1, "  ./fractol mandelbrot\n", 24);
	(void)a;
	a = write(1, "  ./fractol julia 0.245 0.03\n", 29);
	(void)a;
	a = write(1, "  ./fractol burning\n\n", 22);
	(void)a;
	exit(EXIT_SUCCESS);
}

void	parse_arguments(int c, char **v, t_data *data)
{
	data->mx_it = 350;
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
	else if (ft_strncmp(v[1], "burning", ft_strlen("burning") + 1) == 0)
	{
		if (c != 2)
			print_help();
		data->fractal_type = BURNING_SHIP;
	}
	else
		print_help();
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.zoom = 1.0;
	data.offset_x = 0.0;
	data.offset_y = 0.0;
	parse_arguments(argc, argv, &data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		ft_error("Initialization error", EXIT_FAILURE, &data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "fractol");
	if (data.win_ptr == NULL)
		ft_error("Failed to create window", EXIT_FAILURE, &data);
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	if (data.img.img_ptr == NULL)
		ft_error("Failed to create image", EXIT_FAILURE, &data);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	if (data.img.addr == NULL)
		ft_error("Failed to get image address", EXIT_FAILURE, &data);
	render_fractal(&data);
	mlx_hook(data.win_ptr, 4, 1L << 2, mouse_hook, &data);
	mlx_hook(data.win_ptr, DESTROY_NOTIFY, 0, handle_destroy, &data);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
