#include "libft.h"

void *ft_memset(void *str, int c, size_t n)
{
    size_t i;
    unsigned char *ptr;
    
    i = 0;
    ptr = (unsigned char *)str;
    while (i < n)
    {
        ptr[i] = (unsigned char)c;
        i++;
    }
    return (str);
} 