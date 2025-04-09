
#include <string.h> 

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t i;
    size_t dest_long;
    size_t dest_long_copia;
    size_t src_long; 

    i = 0;
    dest_long = 0;
    src_long = 0;
    while (dest[dest_long] != '\0')
        dest_long++;
    dest_long_copia = dest_long;
    while (src[src_long] != '\0')
        src_long++;
    if (size <= dest_long)
        return (size + src_long);
    if (size != 0)
    {
        while (i < size - dest_long - 1 && src[i] != '\0') 
        {
            dest[dest_long_copia] = src[i];
            dest_long_copia++;
            i++;
        }
        if (dest_long_copia < size)
            dest[dest_long_copia] = '\0';
    }
    return (dest_long + src_long);
}