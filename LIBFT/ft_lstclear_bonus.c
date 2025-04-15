#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *copy;
	
	if (!lst || !del)
	{
		return ;
	}
	while (*lst)
	{
		copy = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = copy;
	}
}