/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:23:22 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/26 18:38:01 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iterations, int max_iterations)
{
	int	binary_argb;
	int	r;
	int	g;
	int	b;

	if (iterations == max_iterations)
		return (0x000000);
	r = (iterations * 3) % 256;
	g = (iterations * 8) % 256;
	b = (iterations * 10) % 256;
	binary_argb = ((r << 16) | (g << 8) | b);
	return (binary_argb);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pxl;

	pxl = img->addr + (y * (img->line_len) + x * (img->bpp / 8));
	*(unsigned int *)pxl = color;
}

void	handle_fractal_type(t_data *d, int x, int y)
{
	if (d->fractal_type == MANDELBROT)
	{
		d->c_r = d->offset_x + ((x / (double)WIDTH * 3.0) - 2.0) / d->zoom;
		d->c_i = d->offset_y + ((y / (double)HEIGHT * 3.0) - 1.5) / d->zoom;
		d->z_r = 0.0;
		d->z_i = 0.0;
	}
	else if (d->fractal_type == JULIA)
	{
		d->c_r = d->julia_c_r;
		d->c_i = d->julia_c_i;
		d->z_r = d->offset_x + ((x / (double)WIDTH * 3.0) - 2.0) / d->zoom;
		d->z_i = d->offset_y + ((y / (double)HEIGHT * 3.0) - 1.5) / d->zoom;
	}
}

void	render_fractal(t_data *d)
{
	int	x_px;
	int	y_px;
	int	it;

	y_px = 0;
	while (y_px < HEIGHT)
	{
		x_px = 0;
		while (x_px < WIDTH)
		{
			handle_fractal_type(d, x_px, y_px);
			it = 0;
			while ((d->z_r * d->z_r + d->z_i * d->z_i <= 4) && (it < d->mx_it))
			{
				d->z_r_tmp = (d->z_r * d->z_r) - (d->z_i * d->z_i) + d->c_r;
				d->z_i = (2.0 * d->z_r * d->z_i) + d->c_i;
				d->z_r = d->z_r_tmp;
				it++;
			}
			put_pixel(&d->img, x_px, y_px, get_color(it, d->mx_it));
			x_px++;
		}
		y_px++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.img_ptr, 0, 0);
}
