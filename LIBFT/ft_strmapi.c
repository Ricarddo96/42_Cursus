#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int i;
	char *new_str;

	i = 0;
	if (!s)
		return (NULL);	
	new_str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
