
#include "gnl.h"
#include <stddef.h>
#include <stdlib.h>


size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_long;
	size_t	dest_long_copy;
	size_t	src_long;

	i = 0;
	dest_long = ft_strlen(dest, 0);
	src_long = ft_strlen(src, 0);
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

size_t	ft_strlen(const char *str, int modifier)
{
	size_t	longitud;

	longitud = 0;
	if (modifier == 1)
	{
		if (!str)
			return (0);
	}
	while (str && *str != '\0')
	{
		longitud++;
		str++;
	}
	return (longitud);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
		{
			return ((char *)str + i);
		}
		i--;
	}
	return (NULL);
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
	substring = malloc((len + 1) * sizeof(char));
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1, 1);
	s2_len = ft_strlen(s2, 1);
	total_len = s1_len + s2_len;
	new_str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, total_len + 1);
	ft_strlcat(new_str, s2, total_len + 1);
	*(new_str + total_len) = '\0';
	return (new_str);
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

char *ft_free_and_join(char *stash, char *buffer)
{
    char *temp;

    if (!stash)
        stash = ft_strdup(""); // Si es la primera vez, empezamos con algo vacío
    temp = ft_strjoin(stash, buffer); // Creamos la unión
    free(stash); // ¡LIBERAMOS la versión vieja!
    return (temp); // Devolvemos la nueva
}

// GNL

char *read_and_stash(int fd, char *stash)
{
	char *buffer;
    int bytes_leidos;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_leidos = 1;
	while ((!stash || !ft_strchr(stash, '\n')) && bytes_leidos != 0)
	{
		bytes_leidos = read(fd, buffer, BUFFER_SIZE);
		if (bytes_leidos == -1)
        {
            free(buffer);
            free(stash); // Si hay error de lectura, limpiamos todo
            return (NULL);
        }
		buffer[bytes_leidos] = '\0';
		stash = ft_free_and_join(stash, buffer);
	}
	free(buffer);
	return (stash);
}


char *extract_line(char *stash)
{
    char    *line;
    int     len;


    if (!stash || !stash[0])
        return (NULL);
    len = 0;
    while (stash[len] && stash[len] != '\n')
    {
        len++;
    }
    line = ft_substr(stash, 0, len + (stash[len] == '\n'));
    return (line);
}


char *clean_stash(char *stash)
{
    char    *sobrante;
    int     len;
    int     i;

    len = 0;
    while (stash[len] && stash[len] != '\n')
        len++;
    if (!stash[len])
    {
        free(stash);
        return (NULL);
    }
    sobrante = malloc(sizeof(char) * (ft_strlen(stash, 0) - len)); 
    if (!sobrante)
        return (NULL);
    len++; 
    i = 0;
    while (stash[len])
        sobrante[i++] = stash[len++];
    
    sobrante[i] = '\0';
    free(stash);
    return (sobrante);
}

char *get_next_line(int fd)
{
    static char *stash;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = read_and_stash(fd, stash);
    if (!stash)
        return (NULL);
    line = extract_line(stash);
    stash = clean_stash(stash);
    return (line);
}



int main()
{
	
	int fd = open("archivo.txt", O_RDONLY);
	char *linea;
	int i = 0;

	while (i < 11)
	{
		
		linea = get_next_line(fd);	
		printf("Linea: %s\n", linea);
		free(linea); 
		i++;
	}
	linea = NULL;
	close(fd);
	return (0);
}