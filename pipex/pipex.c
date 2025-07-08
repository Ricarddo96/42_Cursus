#include "pipex.h"

void handle_child1(int infile_fd, int pipe_fd[2], char **path, char **argv, char **env)
{
	int i;
	char *full_path;
	char **args;

	i = 0;
	args = ft_split(argv[2], ' ');
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	while (path[i] != NULL)
	{
		full_path = malloc(ft_strlen(path[i]) + ft_strlen(args[0]) + 2);
		if (!full_path)
			exit(EXIT_FAILURE);
		ft_strcpy(full_path, path[i]);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, args[0]);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free_matrix(args);
			execve(full_path, args, env); // nunca vuelve si funciona
		}
		free(full_path);
		i++;
	}
	free_matrix(args); // importante si nunca entra al if
	perror("falla el hijo 1");
	exit(EXIT_FAILURE);
}

void handle_child2(int outfile_fd, int pipe_fd[2], char **path, char **argv, char **env)
{
	int i;
	char *full_path;
	char **args;

	i = 0;
	args = ft_split(argv[3], ' ');
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	while (path[i] != NULL)
	{
		full_path = malloc(ft_strlen(path[i]) + ft_strlen(args[0]) + 2);
		if (!full_path)
			exit(EXIT_FAILURE);
		ft_strcpy(full_path, path[i]);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, args[0]);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free_matrix(args);
			execve(full_path, args, env);
		}
		free(full_path);
		i++;
	}
	free_matrix(args);
	perror("falla el hijo 2");
	exit(EXIT_FAILURE);
}


int main(int argc, char **argv, char **env)
{
    
	pid_t pid_cmd1;
	pid_t pid_cmd2;
	char **path;
 	int pipe_fd[2];
    int infile_fd;
    int outfile_fd;

	(void)argc; // para el compilador, esto hay que ajustarlo
	infile_fd = -1;
	outfile_fd = -1;
	path = obtain_path(env);
	open_files(&infile_fd, &outfile_fd, argv);
 	if (pipe(pipe_fd) == -1) 
	{ 
        perror("Error al crear pipe_fd");
        exit(EXIT_FAILURE);
    }
	pid_cmd1 = fork();
	if (pid_cmd1 == -1)
	{
		perror("error en fork 1");
		exit(EXIT_FAILURE);
	}
	else if (pid_cmd1 == 0) 
		handle_child1(infile_fd, pipe_fd, path, argv, env);
	pid_cmd2 = fork();
 	if (pid_cmd2 == -1)
	{
		perror("error en fork 2");
		exit(EXIT_FAILURE);
	}
 	if (pid_cmd2 == 0) 
		handle_child2(outfile_fd, pipe_fd, path, argv, env);
	close(infile_fd);
    close(outfile_fd);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
	waitpid(pid_cmd1, NULL, 0);
	waitpid(pid_cmd2, NULL, 0);
	free_matrix(path);
	return (0);
}
