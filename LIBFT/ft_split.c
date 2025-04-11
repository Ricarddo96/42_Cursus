#include "libft.h"

int substr_counter(char const *s, char c)
{
	int i;
	int counter;
	int was_delimit;

	counter = 0;
	was_delimit = 1;
	if (!s || s[0] == '\0')
        return 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (was_delimit)
				counter++;
			was_delimit = 0;
		}
		else
		{
			was_delimit = 1;
		}
		i++;
	}
	return (counter);
}

char **ft_split(char const *s, char c)
{
	size_t i;
	size_t j;
	size_t k;
	size_t s_len; 
	char **matrix;
	
	if (s == NULL)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	matrix = (char **)malloc((substr_counter(s, c) + 1) * sizeof(char *));
	*matrix = (char *)malloc((s_len + substr_counter(s, c))) * sizeof(char);
	if (matrix == NULL)
		return (NULL);
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			matrix[j][k] = s[i];
		}
		i++;
		k++;
		if (s[i] == c)
		{
			matrix[j][k] = '\0';
			j++;
			k = 0;
		}
	}
	return (matrix);
}