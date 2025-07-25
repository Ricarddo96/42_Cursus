/* Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$> */

#include <unistd.h>

void put_str_13(char *str)
{
	int i;
	char c;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			c = ((str[i] - 'a' + 13) % 26) + 'a';
			write(1, &c, 1);
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			c = ((str[i] - 'A' + 13) % 26) + 'A';
			write(1, &c, 1);
		}		
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		put_str_13(argv[1]);
	}
	write(1, "\n", 1);
}