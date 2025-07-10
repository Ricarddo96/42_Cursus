/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ricardo270696@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:25:13 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/10 23:28:04 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char **path, char **args, t_data *data)
{
	int			i;
	char		*full_path;

	i = 0;
	while (path[i] != NULL)
	{
		full_path = malloc(ft_strlen(path[i]) + ft_strlen(args[0]) + 2);
		if (!full_path)
			error("Failed to extract the path", 1);
		ft_strcpy(full_path, path[i]);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, args[0]);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			execve(full_path, args, data->env);
			perror("execve failed");
		}
		free(full_path);
		i++;
	}
	free_matrix(args);
	error("Failed to exectute comand", 2);
}

void	handle_child1(int infile_fd, int pipe_fd[2], t_data *data, char **argv)
{
	char	**args;

	args = ft_split(argv[2], ' ');
	if (dup2(infile_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 infile failed");
		free_matrix(args);
		exit(1);
	}
	close(infile_fd);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 pipe failed");
		free_matrix(args);
		exit(1);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_cmd(data->path, args, data);
}

void	handle_child2(int outfile_fd, int pipe_fd[2], t_data *data, char **argv)
{
	char	**args;

	args = ft_split(argv[3], ' ');
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 pipe failed");
		free_matrix(args);
		exit(1);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 outfile failed");
		free_matrix(args);
		exit(1);
	}
	close(outfile_fd);
	execute_cmd(data->path, args, data);
}

int	close_n_wait(int fd[2], int pipe_fd[2], pid_t pid_cmd[2], char **path)
{
	int	status1;
	int	status2;

	close(fd[0]);
	close(fd[1]);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid_cmd[0], &status1, 0);
	waitpid(pid_cmd[1], &status2, 0);
	free_matrix(path);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid_cmd[2];
	t_data	data;
	int		pipe_fd[2];
	int		fd[2];
	int		status;

	if (argc != 5)
		error("Incorrect number of arguments", 1);
	data.env = env;
	data.path = get_path(data.env);
	open_files(&fd[0], &fd[1], argv);
	if (pipe(pipe_fd) == -1)
		error("Failed to create pipe", 1);
	pid_cmd[0] = fork();
	if (pid_cmd[0] == -1)
		error("Failed to create first fork", 1);
	else if (pid_cmd[0] == 0)
		handle_child1(fd[0], pipe_fd, &data, argv);
	pid_cmd[1] = fork();
	if (pid_cmd[1] == -1)
		error("Failed to create second fork", 1);
	else if (pid_cmd[1] == 0)
		handle_child2(fd[1], pipe_fd, &data, argv);
	status = close_n_wait(fd, pipe_fd, pid_cmd, data.path);
	return (status);
}
