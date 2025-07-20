/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:59:54 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/20 17:01:16 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(char *msg, int code)
{
	write(2, "Error: ", 7);
	write(2, msg, ft_strlen(msg)); 
	write(2, "\n", 1);
	exit(code);
}

void	print_help(void)
{
	write(1, "\nUsage: ./fractol <fractal_name> ", 33);
	write(1, "[optional_julia_parameters]\n\nAvailable fractals:\n\n", 53);
	write(1, "mandelbrot\n", 11);
	write(1, "  julia <real_value> <imaginary_value>\n\n", 41);
	write(1, "Examples:\n\n", 11);
	write(1, "  ./fractol mandelbrot\n", 24);
	write(1, "  ./fractol julia 0.245 0.03\n\n", 30);
	exit(EXIT_SUCCESS);
}
