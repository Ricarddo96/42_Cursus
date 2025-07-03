/* Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$> */

#include <stdio.h>
#include <unistd.h>

int ft_str_len(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

int is_space(char c)
{
    if (c  == ' ' || c == '\t')
        return (1);
    return (0);
}
/* 
void print_rev_wstr(char *str)
{
    int i = ft_str_len(str);
    int end = 0;
    int start = 0;
    int boolean = 0;

    while (i >= 0)
    {
        while (i >= 0 && is_space(str[i]))
            i--;
        if (i < 0)
            break ;
        end = i;
        if (boolean)
            write(1, " ", 1);
        else 
            boolean = 1;
        while (i >= 0 && !is_space(str[i]))
            i--;
        start = i + 1;
        while (start <= end)
        {
            write(1, &str[start++], 1);
        }
    }
} */

void print_rev_wstr(char *s)
{
    int i = ft_str_len(s);
    int start = 0;
    int end = 0;
    int boolean = 0;

    while (i >= 0)
    {
        while (i >= 0 && is_space(s[i]))
            i--;
        if (i < 0)
            break ;
        end = i + 1;

        if (boolean)
            write(1, " ", 1);
        else 
            boolean = 1;
        while (i >= 0 && !is_space(s[i]))
            i--;
        start = i + 1;
        while (start < end)
            write(1, &s[start++],1);     
    }
}

int main(int c, char **v)
{
    if (c == 2)
    {
        print_rev_wstr(v[1]);
    }
    write(1, "\n", 1);
    return (0);
}