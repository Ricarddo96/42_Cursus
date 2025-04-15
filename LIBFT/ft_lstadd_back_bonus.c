#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *copy;

	copy = *lst;
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (copy->next != NULL)
	{
		copy = copy->next;
	}
	copy->next = new; 
}