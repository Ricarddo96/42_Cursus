/* Assignment name  : ft_putstr
Expected files   : ft_putstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that displays a string on the standard output.

The pointer passed to the function contains the address of the string's first
character.

Your function must be declared as follows:

void	ft_putstr(char *str); */

#include <unistd.h>

void ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, &*str++, 1);
}

/* int main(int i, char **e)
{
	ft_putstr(e[1]);
} */