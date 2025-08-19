/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:39:57 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/19 17:40:33 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *stack_receive, t_stack *stack_send)
{
	t_node	*node_to_push;

	if (stack_send->size < 1)
		return ;
	node_to_push = stack_send->first;
	stack_send->first = node_to_push->next;
	if (stack_send->first)
		stack_send->first->prev = NULL;
	else
		stack_send->last = NULL;
	node_to_push->next = NULL;
	node_to_push->prev = NULL;
	if (stack_receive->size == 0)
	{
		stack_receive->first = node_to_push;
		stack_receive->last = node_to_push;
	}
	else
	{
		node_to_push->next = stack_receive->first;
		stack_receive->first->prev = node_to_push;
		stack_receive->first = node_to_push;
	}
	stack_send->size--;
	stack_receive->size++;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
