/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:17:16 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/14 18:12:02 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *next;

    if (!stack)
        return;
    current = stack->first;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

void exit_n_error(char *msg, t_stack *stack_a, t_stack *stack_b)
{
    write(2, msg, ft_strlen(msg));
    if (stack_a)
        free_stack(stack_a);
    if (stack_b)
        free_stack(stack_b);
    exit(EXIT_FAILURE);    
}

int check_number(char *str, t_stack *stack)
{
	long num;
	int i;
	t_node *current_node;

	current_node = stack->last;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		exit_n_error("Error\n", stack, NULL);
	while (str[i])
	{
		if (ft_isdigit(str[i++]) == 0)
			exit_n_error("Error\n", stack, NULL);
	}
	i = 0;
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		exit_n_error("Error\n", stack, NULL);
	if (stack->size > 0)
    {
        current_node = stack->first;
        while (current_node)
        {
            if (current_node->num == (int)num)
                exit_n_error("Error\n", stack, NULL);
            current_node = current_node->next;
        }
    }
	return ((int)num);
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
