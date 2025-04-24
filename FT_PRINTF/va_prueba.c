#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar(2 + '0');
			nb = -147483648;
		}
		nb = -nb;
	}
	if (nb > 9)
	{
		if (nb == 2147483647)
		{
			ft_putchar(2 + '0');
			nb = 147483647;
		}
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}

int suma(int n, ...)
{
    va_list numbers;
    int i;
    int num;
    int suma;

    i = 0;
    suma = 0;
    va_start(numbers, n);
    while (i < n)
    {
        num = va_arg(numbers, int);
        suma = suma + num;
        i++;
    }
    va_end(numbers);
    return (suma);
}

int protoprintf(char *s, ...)
{
    va_list lista;
    int arg;

    va_start(lista, s);
    while (*s != '\0')
    {
        if (*s == '%')
        {
            arg = va_arg(lista, int);
            ft_putnbr(arg);
        }
        else
        {
            ft_putchar(*s);
        }             
        s++;
    }
    va_end(lista);
    return (1);
}
int multi(int n, ...)
{
    va_list argumentos;
    int i = 0;
    int arg = 1;

    va_start(argumentos, n);
    while (i < n)
    {
        arg *= va_arg(argumentos, int);
        i++; 
    }
    va_end(argumentos);
    return (arg);
}
int main()
{
    int s;
    int r;
    int t;

    r = suma(2, 1, 3);
    s = suma(3, 2, 3, 4);
    t = multi(3, 10, 5, 2);
    protoprintf("el resultado de s es % y el resultado de r es %, el de t es una multiplicacion: %", s, r, t);
    // printf("el resultado de la suma es %d", s);
    return (1);
}