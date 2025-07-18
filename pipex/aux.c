/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:28:15 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/18 18:27:59 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg, int code)
{
	write(2, "Error: ", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(code);
}

void	child_error_exit(char *msg, int code, char **args, t_data *data)
{
	if (msg)
		perror(msg);
	if (args)
		free_matrix(args);
	if (data && data->path)
		free_matrix(data->path);
	exit(code);
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

char	**get_path_from_env(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			if (!paths)
				ft_error("Error: Fallo en ft_split al obtener PATH", 1);
			return (paths);
		}
		i++;
	}
	return (NULL);
}

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
