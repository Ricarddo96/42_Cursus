/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:54:39 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/31 17:11:34 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	handle_keypress(int ks, void *d)
{
	t_data	*data;
	int		boolean;

	data = (t_data *)d;
	boolean = 0;
	if (ks == KEY_UP || ks == KEY_DOWN || ks == KEY_RIGHT || ks == KEY_LEFT)
		boolean = 1;
	if (ks == KEY_UP)
		data->offset_y -= 0.1 / data->zoom;
	else if (ks == KEY_DOWN)
		data->offset_y += 0.1 / data->zoom;
	else if (ks == KEY_RIGHT)
		data->offset_x += 0.1 / data->zoom;
	else if (ks == KEY_LEFT)
		data->offset_x -= 0.1 / data->zoom;
	if (ks == KEY_ESC)
	{
		cleanup(d);
		exit(EXIT_SUCCESS);
	}
	if (boolean == 1)
		render_fractal(data);
	return (0);
}

int	handle_destroy(void *d)
{
	t_data	*data;

	data = (t_data *)d;
	cleanup(data);
	exit(EXIT_SUCCESS);
}

int	mouse_hook(int button, int x, int y, t_data *d)
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
