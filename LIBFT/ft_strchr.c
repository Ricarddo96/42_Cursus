#include "libft.h"

char *ft_strchr(const char *str, int c)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == c)
        {
            return (str + i);
        }
        i++;
    }
    if (c == '\0')
    {
        return (str + i);
    }
    return (NULL);
}

/* La función ft_strchr se utiliza para localizar la primera 
ocurrencia de un carácter específico 
dentro de una cadena de caracteres.*/