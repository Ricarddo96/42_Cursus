
#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char *new_string;
	int end;
	int start;
	size_t total_len;
	
	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end >= start && s1[end] && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));

	total_len = (size_t)(end - start + 1);
	new_string = ft_substr(s1, start, total_len);
	return (new_string);
}


