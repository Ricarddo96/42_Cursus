/* Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$> */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
 


int is_space(char c)
{
    if (c == ' ' || c == '\t')
    {
        return (1);
    }
    return (0);
}

void print_shaved(char *s)
{
    int i = 0;
    int space = 0;

    while (is_space(s[i]))
        i++;
    while (s[i])
    {
        if (is_space(s[i]))
            space = 1;
        if (!is_space(s[i]))
        {
            if (space)
            {
                write(1, " ", 1);
                space = 0;
            }
            write(1, &s[i], 1);
        }
        i++;
    }
}

int main(int c, char **v)
{
    if (c == 2)
    {
      print_shaved(v[1]);  
    }
    write(1, "\n", 1);
    return (0);
}

