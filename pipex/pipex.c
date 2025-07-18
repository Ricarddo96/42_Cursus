/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:27:49 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/18 18:25:10 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char **path_env, char **args, t_data *data)
{
	int			i;
	char		*path_with_slash;
	char		*full_path;

	if (!args || !args[0] || ft_strlen(args[0]) == 0)
		child_error_exit("pipex: command not found or empty", 127, args, data);
	i = 0;
	while (path_env[i] != NULL)
	{
		path_with_slash = ft_strjoin(path_env[i], "/");
		if (!path_with_slash)
			child_error_exit("Error: ft_strjoin failed", 1, args, data);
		full_path = ft_strjoin(path_with_slash, args[0]);
		free(path_with_slash);
		if (!full_path)
			child_error_exit("Error: ft_strjoin failed", 1, args, data);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			execve(full_path, args, data->env);
			child_error_exit("pipex: execution failed", 127, args, data);
		}
		free(full_path);
		i++;
	}
	child_error_exit("pipex: command not found", 127, args, data);
}

void	handle_child1(int inf_fd, int pipe_fd[2], t_data *data, char **argv)
{
	char	**args;

	args = ft_split(argv[2], ' ');
	if (!args)
		child_error_exit("Failed to split command arguments", 1, NULL, data);
	if (dup2(inf_fd, STDIN_FILENO) == -1)
		child_error_exit("dup2 infile failed", 1, args, data);
	close(inf_fd);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		child_error_exit("dup2 pipe failed", 1, args, data);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_cmd(data->path, args, data);
}

void	handle_child2(int outf_fd, int pipe_fd[2], t_data *data, char **argv)
{
	char	**args;

	args = ft_split(argv[3], ' ');
	if (!args)
		child_error_exit("Failed to split command arguments", 1, NULL, data);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		child_error_exit("dup2 pipe failed", 1, args, data);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (dup2(outf_fd, STDOUT_FILENO) == -1)
		child_error_exit("dup2 outfile failed", 1, args, data);
	close(outf_fd);
	execute_cmd(data->path, args, data);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 5)
		ft_error("Use: ./pipex <infile> <cmd1> <cmd2> <outfile>", 1);
	data.env = envp;
	data.path = get_path_from_env(envp);
	open_files(&data.infile_fd, &data.outfile_fd, argv);
	if (pipe(data.pipe_fd) == -1)
		ft_error("pipe failed", 1);
	data.pid1 = fork();
	if (data.pid1 == 0)
		handle_child1(data.infile_fd, data.pipe_fd, &data, argv);
	data.pid2 = fork();
	if (data.pid2 == 0)
		handle_child2(data.outfile_fd, data.pipe_fd, &data, argv);
	close(data.pipe_fd[0]);
	close(data.pipe_fd[1]);
	if (data.pid1 != -1)
		waitpid(data.pid1, &data.status1, 0);
	if (data.pid2 != -1)
		waitpid(data.pid2, &data.status2, 0);
	free_matrix(data.path);
	close(data.infile_fd);
	close(data.outfile_fd);
	return (WEXITSTATUS(data.status2));
}
