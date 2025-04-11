#include "libft.h"

size_t ft_strlen(const char *str)
{
    int longitud;

    longitud = 0;
    while (*str != '\0')
    {
        longitud++;
        str++;
    }
    return (longitud);
} 