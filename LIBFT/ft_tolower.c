#include <ctype.h>
#include <stdio.h>

int ft_tolower(int c)
{
    if (c == EOF)
    {
        return EOF;
    }
    unsigned char d;
    d = (unsigned char)c;
    if (d >= 'A' && d <= 'Z')
    {
        return (c + 32);
    }
    return (c);    
}