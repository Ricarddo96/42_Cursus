/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:31:49 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/15 15:50:28 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keysym, void *data)
{
	(void)data;
	if (keysym == 65307)
	{
		write(1, "ESC presionado. Saliendo...\n", 28);
		exit(0);
	}
	return (0);
}

int	handle_destroy(void *data)
{
	(void)data;
	write(1, "Cerrando ventana con la cruz. Saliendo...\n", 42);
	exit(0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Fract-ol: Mi Primera Ventana");
	if (win_ptr == NULL)
	{
		// mlx_destroy_display(mlx_ptr); // Comenta si tu version de mlx no lo tiene
		return (1);
	}

	mlx_key_hook(win_ptr, handle_keypress, NULL);
	mlx_hook(win_ptr, 17, 0, handle_destroy, NULL);

	mlx_loop(mlx_ptr);

	return (0);
}
