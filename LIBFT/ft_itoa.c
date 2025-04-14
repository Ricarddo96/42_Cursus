#include "libft.h"

char *ft_itoa(int n)
{
	size_t contador;
	int n_copy;
	int i;
	char *str;

	n_copy = n;
	contador = 0;
	if (n == 0)
		contador = 1;
	else
	{
		if (n_copy < 0)
			contador++;
		while (n_copy / 10 != 0)
			contador++;
		contador++;
	}
	str = malloc((contador + 1) * sizeof(char));
	i = (int)contador;
	str[i] = '\0';
	i--;
	if (n < 0)
		str[0] = '-';
	while (i >= 0)
	{
		str[i] =  n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
/*
SACAR EL CONTADOR PARA TENER MENOS DE 25 LIN
castar a long
variable para guardar n como long por si el numero mas grannde o el minimo

*/