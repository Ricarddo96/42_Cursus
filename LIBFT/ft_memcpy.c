#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    char *ptr_dest;
    char *ptr_src;
    
    i = 0;
    if ((!dest || !src) && n == 0)
        return (dest);
    ptr_src = (char *)src;
    ptr_dest = (char *)dest;
    while (i < n)
    {
        ptr_dest[i] = ptr_src[i];
        i++;
    }
    return (dest);
}
