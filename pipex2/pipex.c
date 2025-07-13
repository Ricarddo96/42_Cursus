#include "pipex.h"

#include "pipex.h"

void	execute_cmd(char **path_env, char **args, t_data *data)
{
	int			i;
	char		*path_with_slash;
	char		*full_path;

	if (!args || !args[0] || ft_strlen(args[0]) == 0)
		child_error_exit("pipex: Comando vacío o no encontrado", 127, args, data);
	i = 0;
	while (path_env[i] != NULL)
	{
		path_with_slash = ft_strjoin(path_env[i], "/");
		if (!path_with_slash)
			child_error_exit("Error: Fallo en ft_strjoin para la ruta", 1, args, data);
		full_path = ft_strjoin(path_with_slash, args[0]);
		free(path_with_slash);
		if (!full_path)
			child_error_exit("Error: Fallo en ft_strjoin para la ruta completa", 1, args, data);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			execve(full_path, args, data->env);
			child_error_exit("pipex: Fallo de execve", 127, args, data);
		}
		free(full_path);
		i++;
	}
	child_error_exit("pipex: Comando no encontrado o no ejecutable", 127, args, data);
}

void	handle_child1(int infile_fd, int pipe_fd[2], t_data *data, char **argv)
{
	char	**args;

	args = ft_split(argv[2], ' ');
	if (!args)
		child_error_exit("Failed to split command arguments", 1, NULL, data);
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		child_error_exit("dup2 infile failed", 1, args, data);
	close(infile_fd);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		child_error_exit("dup2 pipe failed", 1, args, data);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_cmd(data->path, args, data);
}

void	handle_child2(int outfile_fd, int pipe_fd[2], t_data *data, char **argv)
{
	char	**args;

	args = ft_split(argv[3], ' ');
	if (!args)
		child_error_exit("Failed to split command arguments", 1, NULL, data);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		child_error_exit("dup2 pipe failed", 1, args, data);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		child_error_exit("dup2 outfile failed", 1, args, data);
	close(outfile_fd);
	execute_cmd(data->path, args, data);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		infile_fd;
	int		outfile_fd;
	t_data	data;
	pid_t	pid1;
	pid_t	pid2;
	int		last_exit_status;

	if (argc != 5)
		error("Uso: ./pipex <infile> <cmd1> <cmd2> <outfile>", 1);
	data.env = envp;
	data.path = get_path_from_env(envp);
	open_files(&infile_fd, &outfile_fd, argv);
	if (pipe(pipe_fd) == -1)
		error("pipe failed", 1);
	pid1 = fork();
	if (pid1 == 0)
		handle_child1(infile_fd, pipe_fd, &data, argv);
	pid2 = fork();
	if (pid2 == 0)
		handle_child2(outfile_fd, pipe_fd, &data, argv);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	int status1 = 0;
	int status2 = 0;
	if (pid1 != -1)
		waitpid(pid1, &status1, 0);
	if (pid2 != -1)
		waitpid(pid2, &status2, 0);
	free_matrix(data.path);
	if (infile_fd != -1) close(infile_fd);
	if (outfile_fd != -1) close(outfile_fd);
	last_exit_status = WEXITSTATUS(status2);
	return (last_exit_status);
}

 
