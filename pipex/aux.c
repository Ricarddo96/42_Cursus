#include "pipex.h"

void error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	free_matrix(char **matrix)
{
	int	i;

	if (matrix)
	{
		i = 0;
		while (matrix[i] != NULL)
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
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
char **obtain_path(char **env)
{
	char *uncut_path;
	char **path;

	uncut_path = obtain_uncut_path(env);
	path = ft_split(uncut_path, ':');
	free(uncut_path);
	return (path);
}

void open_files(int *infile, int *outfile, char **argv)
{
		*infile = open(argv[1], O_RDONLY);
		if (*infile == -1 || (access(argv[1], F_OK | R_OK) != 0))
			perror("Error en el infile");
		*outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (*outfile == -1)
		{
			perror("Error en el outfile");
			exit(EXIT_FAILURE);
		}
}
