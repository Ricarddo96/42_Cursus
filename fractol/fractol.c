/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:31:49 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/18 18:40:43 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;

void	ft_error(char *msg, int code)
{
	write(2, "Error: ", 7);
	write(2, msg, ft_strlen(msg)); 
	write(2, "\n", 1);
	exit(code);
}

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

int main()
{
	t_data data;
	
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		ft_error("Initialization error", EXIT_FAILURE);
		
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 800, "fractol");
	if (data.win_ptr == NULL)
		ft_error("Failed to create window", EXIT_FAILURE);
	mlx_hook(data.win_ptr, DESTROY_NOTIFY, 0, handle_destroy, &data);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}	