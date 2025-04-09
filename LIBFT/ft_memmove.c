#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;
    char temp_array[n];
    char *ptr_src;
    char *ptr_dest;

    i = 0;
    ptr_src = (const char *)src;
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
