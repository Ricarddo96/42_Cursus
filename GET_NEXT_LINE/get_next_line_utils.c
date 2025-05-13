/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:19:49 by ridoming          #+#    #+#             */
/*   Updated: 2025/05/09 15:16:43 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str, int modifier)
{
	int	longitud;

	longitud = 0;
	if (str == NULL)
		return (0);
	if (modifier == 1)
	{
		while (*str != '\0')
		{
			longitud++;
			str++;
		}
	}
	else if (modifier == 2)
	{
		while (*str != '\n' && *str != '\0')
		{
			longitud++;
			str++;
		}
	}
	return (longitud);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		s_len;
	char	*new_string;

	i = 0;
	s_len = ft_strlen(s, 1);
	new_string = (char *)malloc(s_len + 1);
	if (new_string == NULL)
		return (NULL);
	while (s[i])
	{
		new_string[i] = s[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s, 1);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	substring = malloc(len + 1 * sizeof(char));
	if (substring == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = *(s + start + i);
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_long;
	size_t	dest_long_copy;
	size_t	src_long;

	i = 0;
	dest_long = ft_strlen(dest, 1);
	src_long = ft_strlen(src, 1);
	dest_long_copy = dest_long;
	if (size <= dest_long)
		return (size + src_long);
	if (size != 0)
	{
		while (i < size - dest_long - 1 && src[i] != '\0')
		{
			dest[dest_long_copy] = src[i];
			dest_long_copy++;
			i++;
		}
		if (dest_long_copy < size)
			dest[dest_long_copy] = '\0';
	}
	return (dest_long + src_long);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		src_long;
	const char	*src_copia;

	src_copia = src;
	i = 0;
	src_long = 0;
	while (*src_copia != '\0')
	{
		src_long++;
		src_copia++;
	}
	if (size != 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_long);
}
