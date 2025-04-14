#include "libft.h"
/*
void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;
    dest = ft_strdup();


    return (dest);
}*/
 
void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;
    char temp_array[n];
    char *ptr_src;
    char *ptr_dest;

    i = 0;
    if ((!dest || !src) && n == 0)
        return (dest);
    ptr_src = (char *)src;
    ptr_dest = (char *)dest;
    while(i < n)
    {
        temp_array[i] = ptr_src[i];
        i++;
    }
    i = 0;
    while(i < n)
    {
        ptr_dest[i] = temp_array[i];
        i++;
    }
    return (dest);
}
