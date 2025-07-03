/* Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3. */

#include <stdlib.h>

int *ft_range(int start, int end)
{
    int num = 0;
    int i = 0;
    int *number;

    if (start > end)
        num = start - end + 1;
    if (end > start)
        num = end - start + 1;
    if (end == start)
        num = 1;
    number = malloc(num * sizeof(int));
    if (!number)
        return (NULL);
    if (end == start)
        number[0] = start;
    if (start > end)
    {
        while (start >= end)
            number[i++] = start--;
    }
    else if (start < end)
    {
        while (start <= end)
        {
            number[i++] = start++;
        }
    }
    return (number);
}

/* int *ft_range(int start, int end)
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
            numbers[i] = start;
            i++;
            start--;
        }
    }
    else if (end > start)
    {
        while (start <= end)
        {
            numbers[i] = start;
            i++;
            start++;
        }
    }  
    else
    {
        numbers[0] = start;
    }
    return (numbers);
} */