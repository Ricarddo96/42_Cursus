#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int list_size;

	list_size = 0;

	while (lst != NULL)
	{
		lst = lst->next;
		list_size++;
	}
	
	return (list_size);
}