/* Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$> */

#include <stdlib.h>
#include <unistd.h>

/* int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return (i);
} */
int is_space(char c)
{
    if (c <= 32)
        return (1);
    return (0);
}

/*  */


void rotstring(char *s)
{
    int i = 0;
    int j = 0;
    int start = 0;
    int end = 0;
    int boolean = 0;
    char *first_word = NULL;

    while (s[i] && is_space(s[i]))
        i++;
    start = i;
    while (s[i] && !is_space(s[i]))
        i++;
    end = i;
    first_word = malloc((end - start + 1) * sizeof(char));
    if (!first_word)
        return ;
    first_word[end - start] = 0;
    while (start < end)
        first_word[j++] = s[start++];
    
    while (s[i])
    {
        while (s[i] && is_space(s[i]))
            i++;
        if (!s[i])
            break ;
        if (boolean)
            write(1, " ", 1);
        else
            boolean = 1;
        while (s[i] && !is_space(s[i]))
        {
            write(1, &s[i++], 1);
        }
    }
    if (boolean && first_word[0])// la segunda parte no es necesaria en el if pero protecion adicional
            write(1, " ", 1);
    j = 0;
    while (first_word[j])
        write(1, &first_word[j++], 1);
    free(first_word);
}


int main(int c, char **v)
{
    if (c >= 2)
        rotstring(v[1]);
    write(1, "\n", 1);
    return (0);
}


