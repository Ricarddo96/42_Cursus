/* Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$ */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int which_lower(int a, int b)
{
    if (a < b)
        return (a);
    else 
        return (b);
}


int hcd(int a, int b)
{
    int i = which_lower(a, b);

    while (!((a % i == 0) && (b % i == 0)))
    {
        i--;
    }
    return (i);
}


int main(int c, char **v)
{
    int result = 0;
    if (c == 3)
    {
        result = hcd(atoi(v[1]), atoi(v[2]));
        printf("%d", result);
    }
    write(1, "\n", 1);
    return (0);
}


/* 
int which_smaller(int a, int b)
{
    if (a < b)
        return (a);
    return (b);
}

void ft_putnbr(int n)
{
    char result = 0;

    if (n > 9)
        ft_putnbr(n / 10);
    result = n % 10 + '0';
    write(1, &result, 1);
}

int main(int c, char **v)
{
    int i;

    i = which_smaller(atoi(v[1]), atoi(v[2]));
    if (c == 3)
    {
        while (!((atoi(v[1])) % i == 0 && ((atoi(v[2])) % i == 0)))
            i--;
        ft_putnbr(i);
    }
    write(1, "\n", 1);
    return (0);
} */