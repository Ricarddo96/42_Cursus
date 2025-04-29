/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:09:07 by ridoming          #+#    #+#             */
/*   Updated: 2025/04/29 18:31:00 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		i += write(1, "(null)", 6);
	}
	else
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_put_pointer(void *p, int fd, char *base)
{
	unsigned long	hexa_pointer;
	int				counter;

	counter = 0;
	if (p == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		hexa_pointer = (unsigned long)p;
		counter += write(fd, "0x", 2);
		counter += ft_putnbr_base(hexa_pointer, fd, base);
	}
	return (counter);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	resultado;
	int		counter;

	counter = 0;
	if (n == -2147483648)
	{
		counter += write(fd, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		counter += write(fd, "-", 1);
		n = -1 * n;
	}
	if (n >= 10)
		counter += ft_putnbr_fd(n / 10, fd);
	resultado = (n % 10) + '0';
	counter += write(fd, &resultado, 1);
	return (counter);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	char			resultado;
	unsigned int	counter;

	counter = 0;
	if (n >= 10)
		counter += ft_putunbr_fd(n / 10, fd);
	resultado = (n % 10) + '0';
	counter += write(fd, &resultado, 1);
	return (counter);
}

int	ft_putnbr_base(unsigned long n, int fd, char *base)
{
	int	counter;

	counter = 0;
	if (n >= 16)
	{
		counter += ft_putnbr_base(n / 16, fd, base);
	}
	counter += write(fd, &base[n % 16], 1);
	return (counter);
}
