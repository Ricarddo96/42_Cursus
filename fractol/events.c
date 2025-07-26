/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:21:58 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/26 19:19:02 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keysym, void *d)
{
	if (keysym == KEY_ESC)
	{
		cleanup(d);
		exit(EXIT_SUCCESS);
	}
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
