/* Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$ */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int ft_atoi(char *s)
{
    int i = 0;
    int result = 0;

    while (s[i] >= '0' && s[i] <= '9')
    {
        result = result * 10 + (s[i] - '0');
        i++;
    }
    return result;
}

void print_hex(int n)
{
    char *hex = "0123456789abcdef";
    char result;
    if (n > 15)
    {
        print_hex(n / 16);
    }
    result = n % 16;
    write(1, &hex[result], 1);
}

int main(int c, char **v)
{
    if (c == 2)
        print_hex(ft_atoi(v[1]));
    write(1, "\n", 1);
    return(0);
}