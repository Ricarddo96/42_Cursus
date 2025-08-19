/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:17:16 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/19 17:37:40 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_a->first = NULL;
	stack_a->last = NULL;
	stack_b->size = 0;
	stack_b->first = NULL;
	stack_b->last = NULL;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

void	exit_n_error(char *msg, t_stack *stack_a, t_stack *stack_b)
{
	write(2, msg, ft_strlen(msg));
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	exit(EXIT_FAILURE);
}

int	stack_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size <= 1)
		return (1);
	current = stack->first;
	while (current && current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

void	final_sort(t_stack *stack_a)
{
	t_node	*min_node;
	int		idx;
	int		steps;

	min_node = get_smallest_node(stack_a);
	idx = get_node_index(min_node, stack_a);
	steps = 0;
	if (idx <= stack_a->size / 2)
	{
		while (idx-- > 0)
			ra(stack_a);
	}
	else
	{
		steps = stack_a->size - idx;
		while (steps-- > 0)
			rra(stack_a);
	}
}
