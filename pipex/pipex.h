#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h> 
#include "./libft/libft.h"


char *obtain_uncut_path(char **env);

#endif
