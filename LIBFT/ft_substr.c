#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substring;
    size_t i;
    size_t s_len;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup(""));
    if (s_len - start < len)
        len = s_len - start;
    substring = malloc(len + 1 * sizeof(char));
    if (substring == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        substring[i] = *(s + start + i);
        i++;    
    }
    substring[i] = '\0';

    return (substring);
}
