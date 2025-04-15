#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned int i;
    unsigned char *ptr_dest;
    unsigned char *ptr_src;
    
    i = 0;
    if ((dest == NULL || src == NULL) && n > 0)
    {
        return (dest);
    }
    if (((!dest || !src) && n == 0))
        return (dest);
    ptr_src = (unsigned char *)src;
    ptr_dest = (unsigned char *)dest;
    while (i < n)
    {
        ptr_dest[i] = ptr_src[i];
        i++;
    }
    return (dest);
}