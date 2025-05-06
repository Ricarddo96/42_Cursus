#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str, int modifier);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

#endif