#include "libft.h"
#include <ctype.h>

int ft_toupper(int c)
{
    if (c == EOF)
    {
        return EOF;
    }
    unsigned char d;
    d = (unsigned char)c;
    if (d >= 'a' && d <= 'z')
    {
        return (c - 32);
    }
    return (c);    
}
