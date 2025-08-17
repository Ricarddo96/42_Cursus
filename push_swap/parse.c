/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:21:27 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/17 17:04:52 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_arguments(char **argv, t_stack *stack_a, t_stack *stack_b)
{
    int i;
	
	i = 1;
	stack_a->first = NULL;
	stack_a->last = NULL;
	stack_a->size = 0;
	create_stack_a(&argv[1], stack_a, stack_b);
}

void parse_string(char **argv, t_stack *stack_a, t_stack *stack_b)
{
    char    **nums;
    int     i;

	i = 0;
    stack_a->first = NULL;
    stack_a->last = NULL;
    stack_a->size = 0;
    nums = ft_split(argv[1], ' ');
    if (!nums || !nums[0])
	{
        exit_n_error("Error\n", stack_a, stack_b);
	}
	create_stack_a(nums, stack_a, stack_b);
    while (nums[i])
        free(nums[i++]);
    free(nums);
}

void create_stack_a(char **nums, t_stack *stack_a, t_stack *stack_b)
{
	int i;
	t_node *current_node;
	
	current_node = NULL;
	i = 0;
	while (nums[i])
    {
        check_number(nums[i], stack_a);
        current_node = create_node(ft_atol(nums[i]), stack_a, stack_b);
        if (stack_a->size == 0)
        {
            stack_a->first = current_node;
            stack_a->last = current_node;
        }
        else
        {
            current_node->prev = stack_a->last;
            stack_a->last->next = current_node;
            stack_a->last = current_node;
        }
        stack_a->size++;
        i++;
    }
}

int check_number(char *str, t_stack *stack)
{
	long num;
	int i = 0;
	t_node *current;

	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		exit_n_error("Error\n", stack, NULL);
	while (str[i])
		if (!ft_isdigit(str[i++]))
			exit_n_error("Error\n", stack, NULL);
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		exit_n_error("Error\n", stack, NULL);
	current = stack->first;
	while (current)
	{
		if (current->num == (int)num)
			exit_n_error("Error\n", stack, NULL);
		current = current->next;
	}
	return ((int)num);
}
