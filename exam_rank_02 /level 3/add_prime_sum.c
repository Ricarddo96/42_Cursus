/* Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$> */


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int is_prime(int num)
{
    int i;

    i = 2;
    if (num < 2)
        return (0);
    while (i <= (num / 2))
    {
        if (num % i == 0)
        {
            return(0);
        }
        i++;
    }
    return (num);
}

int ft_atoi(char *str)
{
    int res = 0;
    int sign = 1; 
    int i = 0;

    while (str[i] == ' ')
        i++;
    if (str[i] == '+' || str[i] == '-')
        if (str[i++] == '-')
            sign = -1;
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        res *= 10;
        res += str[i] - '0';
        i++;
    }
    res *= sign;
    return (res);
}

void ft_putnbr(int n)
{
    int result;

    result = 0;
    if (n < 0)
    {
        n = n * -1;
        write(1, "-", 1);
    }
    if (n > 9)
    {
        ft_putnbr(n / 10);
    }
    result = n % 10 + '0';
    write(1, &result, 1);
}

int main(int c, char **v)
{
    int i;
    int result;

    i = 0;
    result = 0;
    if (c == 2 && v[1][0] != '-')
    {
        while (i <= ft_atoi(v[1]))
        {
            result += is_prime(i);
            i++;
        }
        ft_putnbr(result);        
    }
    write(1, "\n", 1);
    return (0);
}
