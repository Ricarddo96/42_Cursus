/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ricardo270696@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:30:16 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/10 23:31:31 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg, int mod)
{
	if (mod == 1)
	{
		perror(msg);
		exit(EXIT_FAILURE);
	}
	if (mod == 2)
	{
		perror(msg);
		exit(127);
	}
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

char	**get_path(char **env)
{
	char	*uncut_path;
	char	**path;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
	{
		perror("PATH no encontrado");
		return (NULL);
	}
	uncut_path = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
	path = ft_split(uncut_path, ':');
	free(uncut_path);
	return (path);
}

void	open_files(int *infile, int *outfile, char **argv)
{
	*infile = open(argv[1], O_RDONLY);
	if (*infile == -1 || (access(argv[1], F_OK | R_OK) != 0))
		perror("Infile error");
	*outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*outfile == -1)
		perror("Outfile error");
}
