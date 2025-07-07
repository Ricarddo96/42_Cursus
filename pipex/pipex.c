#include "pipex.h"



int main(int argc, char **argv, char **env)
{
    
	pid_t pid_ls;
	pid_t pid_grep;
	int i = 0;
	char *full_path = NULL;
	char **path;
	char **args = ft_split(argv[2], ' ');
	char **args2 = ft_split(argv[3], ' ');
 	int pipe_fd[2];   // Primer pipe: ls -> grep
	int status;
    int infile_fd;
    int outfile_fd;// HAY QUE CAMBIAARSELO AL 4 EL 2 ES SOLO PARA LA PRUEBA

	(void)argc; // para el compilador, esto hay que ajustarlo

	path = ft_split(obtain_uncut_path(env), ':');


	if (access(argv[1], R_OK) == 0 && access(argv[4], W_OK) == 0)
	{
		infile_fd = open(argv[1], O_RDONLY);
		if (infile_fd == -1)
		{
			perror("Error en el infile");
			exit(EXIT_FAILURE);
		}
		outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile_fd == -1)
		{
			perror("Error en el outfile");
			exit(EXIT_FAILURE);
		}
	}
	else 
	{
		perror("Permisos denegados");
		exit(EXIT_FAILURE);
	}


 	if (pipe(pipe_fd) == -1) { 
        perror("Error al crear pipe_fd");
        exit(EXIT_FAILURE);
    }
 	
	pid_ls = fork();
	if (pid_ls == -1)
	{
		perror("error en fork de ls");
		exit(EXIT_FAILURE);
	}
	else if (pid_ls == 0) 
	{
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
			execve(full_path, args, env); // <-- usa env en vez de NULL
			free(full_path);
			i++;
		}
		perror("falla el hijo ls");
		exit(EXIT_FAILURE);
	}
	
	pid_grep = fork();
 	if (pid_grep == -1)
	{
		perror("error en fork de grep");
		exit(EXIT_FAILURE);
	}
 	if (pid_grep == 0) 
 	{
		i = 0;
 		dup2(pipe_fd[0], STDIN_FILENO);   // Entrada de grep viene de pipe_fd
 		close(pipe_fd[0]);                // Cierra extremo de lectura original de pipe_fd
 		close(pipe_fd[1]);                // Cierra extremo de escritura de pipe_fd (¡importante para EOF de ls!)
 		dup2(outfile_fd, STDOUT_FILENO);
        close(outfile_fd);
		while (path[i] != NULL)
		{
			full_path = malloc(ft_strlen(path[i]) + ft_strlen(args2[0]) + 2);
			if (!full_path)
				exit(EXIT_FAILURE);
			ft_strcpy(full_path, path[i]);
			ft_strcat(full_path, "/");
			ft_strcat(full_path, args2[0]);
			execve(full_path, args2, env);
			free(full_path);
			i++;
		}
		perror("falla el hijo grep");
		exit(EXIT_FAILURE);
 	}
 	
 	close(infile_fd);
    close(outfile_fd);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    
    
 	waitpid(pid_ls, &status, 0);
	waitpid(pid_grep, &status, 0);

	return (0);
}
