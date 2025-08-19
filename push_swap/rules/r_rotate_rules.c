/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:45:12 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/19 17:46:24 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*last_node;

	if (stack->size < 2)
		return ;
	last_node = stack->last;
	last_node->next = stack->first;
	stack->last = last_node->prev;
	stack->last->next = NULL;
	last_node->prev = NULL;
	stack->first->prev = last_node;
	stack->first = last_node;
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
