/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:28:08 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/14 18:36:53 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_data
{
	pid_t	pid1;
	pid_t	pid2;
	char	**path;
	char	**env;
	int		pipe_fd[2];
	int		infile_fd;
	int		outfile_fd;
	int		status1;
	int		status2;
}				t_data;

void	error(char *msg, int mod);
void	child_error_exit(char *msg, int code, char **args, t_data *data);
void	open_files(int *infile, int *outfile, char **argv);
void	execute_cmd(char **path_env, char **args, t_data *data);
void	handle_child1(int inf_fd, int pipe_fd[2], t_data *data, char **argv);
void	handle_child2(int outf_fd, int pipe_fd[2], t_data *data, char **argv);
void	close_n_wait(int *pipe_fd, t_data *data, pid_t pid1, pid_t pid2);
char	**get_path_from_env(char **envp);
void	free_matrix(char **matrix);

#endif