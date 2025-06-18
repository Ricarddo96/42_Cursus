/* Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$> */

#include <unistd.h>

int main(int counter, char **v)
{
	int i;
	char c;

	i = 0;
	if (counter == 2)
	{
		while (v[1][i])
		{
			if (v[1][i] >= 'a' && v[1][i] <= 'z')
			{
				c = 'z' - v[1][i] + 'a';
				write(1, &c, 1);
			}
			else if (v[1][i] >= 'A' && v[1][i] <= 'Z')
			{
				c = 'Z' - v[1][i] + 'A';
				write(1, &c, 1);
			}
			else
				write(1, &v[1][i], 1);
			i++;
		}
	}
	return (0);
}
