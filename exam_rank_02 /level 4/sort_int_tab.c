/* Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
 */

#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;
    unsigned int j;
    int temp;

    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if(tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
            j++;
        }   
        i++;
    }
}

int main(void)
{
    int arr[] = {5, 3, 8, 1, 2};
    unsigned int size = sizeof(arr) / sizeof(arr[0]);

    sort_int_tab(arr, size);

    for (unsigned int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}