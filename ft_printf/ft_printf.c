/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:14:21 by ridoming          #+#    #+#             */
/*   Updated: 2025/04/29 18:26:12 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	handle_arg_type(char c, va_list list)
{
	unsigned int	counter;
	char			*hexa_min;
	char			*hexa_may;

	hexa_min = "0123456789abcdef";
	hexa_may = "0123456789ABCDEF";
	counter = 0;
	if (c == 'c')
		counter = ft_putchar(va_arg(list, int));
	else if (c == 's')
		counter = ft_putstr_fd(va_arg(list, char *), 1);
	else if (c == 'p')
		counter = ft_put_pointer(va_arg(list, void *), 1, hexa_min);
	else if (c == 'd' || c == 'i')
		counter = ft_putnbr_fd(va_arg(list, int), 1);
	else if (c == 'u')
		counter = ft_putunbr_fd(va_arg(list, unsigned int), 1);
	else if (c == '%')
		counter = write(1, "%", 1);
	else if (c == 'x')
		counter = ft_putnbr_base(va_arg(list, unsigned int), 1, hexa_min);
	else if (c == 'X')
		counter = ft_putnbr_base(va_arg(list, unsigned int), 1, hexa_may);
	return (counter);
}

int	ft_printf(char const *format, ...)
{
	va_list	list;
	int		char_counter;
	int		i;

	va_start(list, format);
	i = 0;
	char_counter = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			char_counter += handle_arg_type(format[i], list);
		}
		else
		{
			ft_putchar(format[i]);
			char_counter++;
		}
		i++;
	}
	va_end(list);
	return (char_counter);
}
