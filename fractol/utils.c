/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:59:54 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/23 12:55:59 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(char *msg, int code)
{
    ssize_t a;

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
    ssize_t a;

	a = write(1, "\nUsage: ./fractol <fractal_name> ", 33);
    (void)a;
	a = write(1, "[optional_julia_parameters]\n\nAvailable fractals:\n\n", 51);
    (void)a;
	a = write(1, "mandelbrot\n", 11);
    (void)a;
	a = write(1, "  julia <real_value> <imaginary_value>\n\n", 41);
    (void)a;
	a = write(1, "Examples:\n\n", 11);
    (void)a;
	a = write(1, "  ./fractol mandelbrot\n", 24);
    (void)a;
	a = write(1, "  ./fractol julia 0.245 0.03\n\n", 30);
    (void)a;
	exit(EXIT_SUCCESS);
}
