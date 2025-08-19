/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:11:42 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/19 17:33:15 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int num, t_stack *stack_a, t_stack *stack_b)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit_n_error("Error\n", stack_a, stack_b);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->num = num;
	return (new_node);
}

void	order_two_numbers(t_stack *stack_a)
{
	int	num_1;
	int	num_2;

	num_1 = stack_a->first->num;
	num_2 = stack_a->last->num;
	if (num_1 > num_2)
	{
		sa(stack_a);
	}
	return ;
}

void	order_three_numbers(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->first->num;
	second = a->first->next->num;
	third = a->last->num;
	if (first < second && second < third)
		return ;
	else if (first < third && third < second)
	{
		sa(a);
		ra(a);
	}
	else if (second < first && first < third)
		sa(a);
	else if (second < third && third < first)
		ra(a);
	else if (third < first && first < second)
		rra(a);
	else if (third < second && second < first)
	{
		sa(a);
		rra(a);
	}
}

void	turk_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_a->size > 3)
		main_loop(stack_a, stack_b);
	order_three_numbers(stack_a);
	while (stack_b->size > 0)
		main_loop_back(stack_a, stack_b);
	if (!stack_sorted(stack_a))
		final_sort(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		exit_n_error("Error\n", stack_a, stack_b);
	init_stacks(stack_a, stack_b);
	if (argc == 2)
		parse_string(argv, stack_a, stack_b);
	else if (argc > 2)
		parse_arguments(argv, stack_a, stack_b);
	if (stack_a->size == 2)
		order_two_numbers(stack_a);
	else if (stack_a->size == 3)
		order_three_numbers(stack_a);
	else if (stack_a->size > 3)
		turk_algorithm(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
