/* Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $ */

#include <unistd.h>

int my_str_len(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int check_args(char *a, char *b)
{
	if(my_str_len(a) == 1 && my_str_len(b) == 1)
	{
		if ((a[0] <= 'z' && a[0] >= 'a') && (b[0] <= 'z' && b[0] >= 'a'))
			return (1);
		else
			return (0);
	}
	return (0);
}

int main(int c, char **v)
{
	int i;

	i = 0;
	if (c == 4)
	{
		if (check_args(v[2], v[3]))
		{
			while (v[1][i])
			{
				if (v[1][i] == v[2][0])
					write(1, &v[3][0], 1);
				else
					write(1, &v[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
}