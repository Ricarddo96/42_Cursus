/* Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr); */

#include <stdlib.h>

int	ft_count_len(int nbr)
{
	int	i;

	i = 0;    
	if (nbr <= 0)
		i++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int number)
{
    long nbr = number;
    int len = ft_count_len(nbr);
    char *str = malloc(len + 1);
    int start = 0;

    if (str == NULL)
        return (NULL);

    str[len] = '\0';
    len--;
    if (nbr == 0)
        str[0] = '0';
    if (nbr < 0)
    {
        str[0] = '-';
        nbr *= -1;
        start = 1;
    }
    while (len >= start)
    {
        str[len] = nbr % 10 + '0';
        nbr = nbr / 10;
        len--;
    }
    return(str);
}