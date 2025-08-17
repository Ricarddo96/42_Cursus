/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:11:42 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/17 16:26:39 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void order_two_numbers(t_stack *stack_a)
{
    int num_1;
    int num_2;
    
    num_1 = stack_a->first->num;
    num_2 = stack_a->last->num;
    if (num_1 > num_2)
    {
        sa(stack_a);
    }
    return;
}

void order_three_numbers(t_stack *stack_a)
{
    int first_num = stack_a->first->num;
    int second_num = stack_a->first->next->num;
    int third_num = stack_a->last->num;

    if (first_num < second_num && second_num < third_num)
        return;
    else if (first_num < second_num && third_num < second_num)
    {
        rra(stack_a);
        sa(stack_a);
    }
    else if (third_num < first_num && first_num < second_num)
        rra(stack_a);
    else if (third_num < second_num && second_num < first_num)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (second_num < first_num && first_num < third_num)
        sa(stack_a);
    else if (second_num < third_num && third_num < first_num)
        ra(stack_a);
}

t_node *create_node(int num, t_stack *stack_a, t_stack *stack_b)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit_n_error("Error\n", stack_a, stack_b);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->num = num;
	return (new_node);
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		exit_n_error("Error\n", stack_a, stack_b);
	if (argc == 2)
        parse_string(argv, stack_a, stack_b);
    else if (argc > 2)
        parse_arguments(argv, stack_a, stack_b);
    if (stack_a->size == 2)
        order_two_numbers(stack_a);
    else if (stack_a->size == 3)
        order_three_numbers(stack_a);
    else if (stack_a->size > 3) 
    {
        pb(stack_a, stack_b);
        pb(stack_a, stack_b);
        while (stack_a->size > 3)
            main_loop(stack_a, stack_b);
        order_three_numbers(stack_a);
        while (stack_b->size > 0)
            main_loop_back(stack_a, stack_b);
        final_sort(stack_a);
    }
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}
