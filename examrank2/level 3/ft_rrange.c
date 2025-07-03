/* Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0. */

#include <stdlib.h>




/* 
int *ft_rrange(int start, int end)
{
    int i;
    int num;
    int *numbers;

    num = 0;
    i = 0;
    if (start > end)
        num = start - end + 1;
    else if (end > start)
        num = end - start + 1;
    else
        num = 1;
    numbers = malloc(num * sizeof(int));
    if (start > end)
    {
        while (end <= start)
        {
            numbers[i] = end;
            i++;
            end++;
        }
    }
    else if (end > start)
    {
        while (start <= end)
        {
            numbers[i] = end;
            i++;
            end--;
        }
    }  
    else
    {
        numbers[0] = start;
    }
    return (numbers);
} */