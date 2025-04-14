#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *memoria;

    if (nmemb > __SIZE_MAX__ / size)
    {
        return NULL;
    }

    memoria = (char *)malloc(nmemb * size);

    if (memoria == NULL)
    {
        return NULL;
    }

    ft_memset(memoria, 0, nmemb * size);

    return (memoria);
}