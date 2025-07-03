/* Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$> */

#include <unistd.h>

void ft_putnbr(int num)
{
    char result = 0;
    if (num > 9)
    {
        ft_putnbr(num / 10);
    }
    result = (num % 10) + '0';
    write(1, &result, 1); 

}

int main(int c, char **v)
{
    int args = 0;

    (void)v;
    args = c - 1;
    ft_putnbr(args);
    write(1, "\n", 1);
    return (0);
}