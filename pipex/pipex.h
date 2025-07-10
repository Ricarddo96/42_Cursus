/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ricardo270696@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:31:47 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/10 23:32:10 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_data
{
	char	**path;
	char	**env;
}	t_data;

void	error(char *msg, int mod);
char	**get_path(char **env);
void	free_matrix(char **matrix);
void	open_files(int *infile, int *outfile, char **argv);
void	execute_cmd(char **path, char **args, t_data *data);
void	handle_child1(int infile_fd, int pipe_fd[2], t_data *data, char **argv);
void	handle_child2(int outfile_fd, int pipe_fd[2], t_data *data, char **argv);
int		close_n_wait(int fd[2], int pipe_fd[2], pid_t pid_cmd[2], char **path);

#endif
