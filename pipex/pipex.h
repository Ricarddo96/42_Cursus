#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h> 

int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strlen(const char *str);
char *obtain_uncut_path(char **env);

#endif
