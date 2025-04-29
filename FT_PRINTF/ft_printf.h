/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:33:40 by ridoming          #+#    #+#             */
/*   Updated: 2025/04/29 18:25:43 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h> 
# include <stddef.h>
# include <stdlib.h> 

int	ft_putstr_fd(char *s, int fd);
int	ft_put_pointer(void *p, int fd, char *base);
int	ft_putnbr_fd(int n, int fd);
int	ft_putunbr_fd(unsigned int n, int fd);
int	ft_putnbr_base(unsigned long n, int fd, char *base);
int	ft_printf(char const *format, ...);

#endif
