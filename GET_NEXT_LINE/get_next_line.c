/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:19:13 by ridoming          #+#    #+#             */
/*   Updated: 2025/05/13 17:08:19 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
		{
			return ((char *)str + i);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)str + i);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	char	*new_str;

	if (!s2)
		return (NULL);
	if (!s1)
		return (new_str = ft_strdup(s2));
	s1_len = ft_strlen(s1, 1);
	s2_len = ft_strlen(s2, 1);
	total_len = s1_len + s2_len;
	new_str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (free(s1), NULL);
	ft_strlcpy(new_str, s1, total_len + 1);
	ft_strlcat(new_str, s2, total_len + 1);
	return (new_str);
}

static int	read_to_buffer(int fd, char **buffer)
{
	char	*buffer_temp;
	char	*temp;
	int		bytes_leidos;

	buffer_temp = malloc(BUFFER_SIZE + 1);
	if (!buffer_temp)
		return (-1);
	bytes_leidos = 1;
	while (ft_strchr(*buffer, '\n') == NULL)
	{
		bytes_leidos = read(fd, buffer_temp, BUFFER_SIZE);
		if (bytes_leidos <= 0)
			break ;
		buffer_temp[bytes_leidos] = '\0';
		temp = ft_strjoin(*buffer, buffer_temp);
		if (!temp)
			return (free(buffer_temp), free(*buffer), *buffer = NULL, -1);
		free(*buffer);
		*buffer = temp;
	}
	free(buffer_temp);
	return (bytes_leidos);
}

static char	*extract_line(char **buffer)
{
	char	*linea;
	char	*temp;
	int		len;

	len = ft_strlen(*buffer, 2);
	linea = ft_substr(*buffer, 0, len);
	if (!linea)
		return (free(*buffer), *buffer = NULL, NULL);
	if (ft_strchr(*buffer, '\n'))
	{
		temp = ft_strjoin(linea, "\n");
		free(linea);
		if (!temp)
			return (free(*buffer), *buffer = NULL, NULL);
		linea = temp;
		len++;
	}
	temp = ft_substr(*buffer, len, ft_strlen(*buffer + len, 1));
	free(*buffer);
	*buffer = temp;
	return (linea);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd = read_to_buffer(fd, &buffer);
	if (rd == -1)
		return (free(buffer), buffer = NULL, NULL);
	if (!buffer || buffer[0] == '\0')
		return (free(buffer), buffer = NULL, NULL);
	return (extract_line(&buffer));
}
/* 
int main()
{
	
	int fd = open("holi.txt", O_RDONLY);
	char *linea;
	int i = 0;

	while (i < 10)
	{
		
		linea = get_next_line(fd);	
		printf("Linea: %s\n", linea);
		free(linea); 
		i++;
	}
	linea = NULL;
	close(fd);
	return (1);
}   */