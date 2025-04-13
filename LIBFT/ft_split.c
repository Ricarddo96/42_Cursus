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
	size_t start;
	size_t substr_len; 
	char **matrix;
	
	if (s == NULL)
		return (NULL);
	matrix = (char **)malloc((substr_counter(s, c) + 1) * sizeof(char *));
	if (matrix == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			substr_len = 0;
			start = i;
			while (s[i + substr_len] != c)
				substr_len++;
			i = i + substr_len;
			matrix[j] = malloc((substr_len + 1) * sizeof(char));	
		}
		ft_strlcpy(matrix[j], &s[start], substr_len + 1);
		j++;
	}
	matrix[j] = NULL;
	return (matrix);
}
