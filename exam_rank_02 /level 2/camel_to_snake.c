/* Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$ */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

int check_if_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int count_(char *s)
{
	int i = 0, count = 0;
	while (s[i])
	{
		if (check_if_upper(s[i]))
			count++;
		i++;
	}
	return count;
}
int is_lower_case(char *s)
{
	if(s[0] <= 'z' && s[0] >= 'a')
		return(1);
	return(0);
}

int main(int argc, char **argv)
{
	int i;
	int j;
	char *snake_case;
	
	i = 0;
	j = 0;
	if (argc == 2)
	{
		if (is_lower_case(argv[1]))
		{
			i = ft_strlen(argv[1]);
			j = count_(argv[1]) + i;
			snake_case = malloc(j + 1 * sizeof(char));
			snake_case[j - 1] = '\0';
			j--;
			while (i >= 0)
			{
				if (check_if_upper(argv[1][i]))
				{
					snake_case[j - 1] = argv[1][i] + 32;
					j--;
					snake_case[j - 1] = '_';
				}
				else
				{
					snake_case[j - 1] = argv[1][i];
				}
				i--;
				j--;
			}
		}

	}
}