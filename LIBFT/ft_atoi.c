#include <stdlib.h>

int ft_atoi(const char *nptr)
{
    int i;
    char signo;
    int resultado;

    i = 0;
    while (nptr[i] > 9 && nptr[i] < 13 || nptr[i] == 32)
        i++;
    if (nptr[i] == '-' || nptr[i] == '+')
        signo = nptr[i];
        i++;
    while(nptr[i] > '0')
    {

    }
    
}