#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		if (s1[i] == '\0' || s2[i] == '\0')
		{
		    break ;
		}
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	longitud;

	longitud = 0;
	while (*str != '\0')
	{
		longitud++;
		str++;
	}
	return (longitud);
}

char *obtain_uncut_path(char **env)
{
    int i;
    int j;
    int k;
    int env_len;
    char *path = NULL;
    
    i = 0;
    j = 5;
    k = 0;
    env_len = 0;
    while (env[i] && (ft_strncmp(env[i], "PATH=", 5) != 0))
        i++;
    if (!env[i])
    {
        perror("PATH no encontrado");
        return(NULL);
    }
    env_len = ft_strlen(env[i]);
    path = malloc((env_len - 5 + 1) * sizeof(char));
    if (!path)
        return (NULL);
    while (j < env_len)
        path[k++] = env[i][j++]; 
    path[k] = '\0';
    return (path);
}
