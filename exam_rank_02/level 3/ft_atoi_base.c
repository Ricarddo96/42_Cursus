/* Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base); */


#include <stdio.h>

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return (c);
}

int get_digit(char c, int base)
{
    c = to_lower(c);
    if (c <= '9' && c >= '0')
    {
        if (c - '0' < base)
            return(c - '0');
    }
    else if (c <= 'f' && c >= 'a')
    {
        if ((c - 'a' + 10) < base)
            return(c - 'a' + 10);
    }
    return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
    int result;
    int sign;

    sign = 1;
    result = 0;
    if (str[0] == '+' || str[0] == '-')
    {
        if (str[0] == '-')
            sign = -1;
        str++;
    }
    while (get_digit(to_lower(*str), str_base) >= 0)
    {
        result *= str_base;
        result += get_digit(to_lower(*str), str_base);
        ++str; 
    }
    return (result * sign);
}



