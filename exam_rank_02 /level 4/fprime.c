/* Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$ */

#include <stdio.h>
#include <stdlib.h>

void fprime(int nbr)
{
    int i = 2;
    int boolean = 0; 
    if (nbr == 1)
    {
        printf("1");
        return ;
    }
    while (nbr > 1)
    {
        if (nbr % i == 0)
        {
            if (boolean)
                printf("*");
            nbr = nbr / i;
            printf("%d", i);
            boolean = 1;
        }
        else
            i++;
    }
}

int main(int c, char **v)
{
    if (c == 2)
    {
        fprime(atoi(v[1]));
    }
    printf("\n");
    return (0);
}
