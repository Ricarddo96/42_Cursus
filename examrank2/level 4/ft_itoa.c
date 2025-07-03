/* Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr); */

#include <stdlib.h>
/* 
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
} */

int num_len(int num)
{
    int i = 0;
    if (num <= 0)
        i++;
    while (num != 0)
    {
        num /= 10;
        i++;
    }
    return (i);
}


/* char	*ft_itoa(int num)
{
	long	n = num;
	int		len = num_len(n);
	char	*s = malloc(len + 1);
	if (!s)
		return (NULL);

	s[len] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		s[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
} */

char *ft_itoa(int num)
{
    long n = num;
    int len = num_len(n);
    char *s = malloc((len + 1) * sizeof(char));
    if (!s)
        return (NULL);
    s[len] = '\0';
    if (n == 0)
    {
        s[0] = '0';
        return (s);
    }
    if (n < 0)
    {
        s[0] = '-';
        n = -n;
    }
    while (n > 0)
    {
        s[--len] = (n % 10) + '0';
        n /= 10;
    }
    return (s);
}

int main(void)
{
    printf("%s\n", ft_itoa(0));             // "0"
    printf("%s\n", ft_itoa(123));           // "123"
    printf("%s\n", ft_itoa(-456));          // "-456"
    printf("%s\n", ft_itoa(2147483647));    // "2147483647"
    printf("%s\n", ft_itoa(-2147483648));   // "-2147483648"
}