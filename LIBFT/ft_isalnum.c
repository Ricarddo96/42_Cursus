/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:33:00 by ridoming          #+#    #+#             */
/*   Updated: 2025/04/18 13:34:21 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	int	is_alpha;
	int	is_digit;

	is_alpha = ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
	is_digit = (c >= '0' && c <= '9');
	return (is_alpha || is_digit);
}
