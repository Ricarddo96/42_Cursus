#include "pipex.h"

void execute_cmd(char **path, char **args)
{
	int i;
	char *full_path;

	i = 0;
	while (path[i] != NULL)
	{
		full_path = malloc(ft_strlen(path[i]) + ft_strlen(args[0]) + 2);
		if (!full_path)
			error();
		ft_strcpy(full_path, path[i]);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, args[0]);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free_matrix(args);
			execve(full_path, args, NULL);
		}
		free(full_path);
		i++;
	}
	free_matrix(args);
	error();
}

void handle_child1(int infile_fd, int pipe_fd[2], char **path, char **argv)
{
	char **args;

	args = ft_split(argv[2], ' ');
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_cmd(path, args);
}

void handle_child2(int outfile_fd, int pipe_fd[2], char **path, char **argv)
{
	char **args;

	args = ft_split(argv[3], ' ');
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	execute_cmd(path, args);
}

int close_n_wait(int fd[3], int pipe_fd[2], pid_t pid_cmd[2], char **path)
{
	close(fd[0]);
    close(fd[1]);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
	waitpid(pid_cmd[0], &fd[2], 0);
	waitpid(pid_cmd[1], &fd[2], 0);
	free_matrix(path);
	if (WIFEXITED(fd[2]))
        return (WEXITSTATUS(fd[2]));
	return (0);
}

int main(int argc, char **argv, char **env)
{
	pid_t pid_cmd[2];
	char **path;
 	int pipe_fd[2];
    int fd_n_status[3];

	if (argc != 5)
		error();
	path = obtain_path(env);
	open_files(&fd_n_status[0], &fd_n_status[1], argv);
 	if (pipe(pipe_fd) == -1) 
		error();
	pid_cmd[0] = fork();
	if (pid_cmd[0] == -1)
		error();
	else if (pid_cmd[0] == 0) 
		handle_child1(fd_n_status[0], pipe_fd, path, argv);
	pid_cmd[1] = fork();
 	if (pid_cmd[1] == -1)
		error();
 	else if (pid_cmd[1] == 0) 
		handle_child2(fd_n_status[1], pipe_fd, path, argv);
	close_n_wait(fd_n_status, pipe_fd, pid_cmd, path);
	return (0);
}
