/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:11:42 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/10 17:17:22 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void exit_n_error(char *msg, int mod)
{
	if (mod == 1)
	{
		write(2, msg, ft_strlen(msg));
		exit(EXIT_FAILURE);	
	}
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
		exit_n_error("Error\n", 1);
	while (str[i])
	{
		if (ft_isdigit(str[i++]) == 0)
			exit_n_error("Error\n", 1);
	}
	i = 0;
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		exit_n_error("Error\n", 1);
	if (stack->size > 0)
    {
        current_node = stack->first;
        while (current_node)
        {
            if (current_node->num == (int)num)
                exit_n_error("Error\n", 1);
            current_node = current_node->next;
        }
    }
	return ((int)num);
}
t_node *create_node(int num)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit_n_error("Error\n", 1); // de momento no se si hay que hacer un cleanup aqui
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->num = num;
	return (new_node);
}

void	parse_arguments(char **argv, t_stack *stack)
{
	t_node *current_node;
    int i;
	
	i = 1;
	stack->first = NULL;
	stack->last = NULL;
	stack->size = 0;
	while (argv[i])
	{
		check_number(argv[i], stack);
		current_node = create_node(ft_atol(argv[i]));
		if (stack->size == 0)
		{
			stack->first = current_node;
			stack->last = current_node;
		}
		else 
		{
			current_node->prev = stack->last;
			stack->last->next = current_node;
			stack->last = current_node;
		}
		stack->size++;
		i++;	
	}
}

void order_three_numbers(t_stack *stack_a)
{
    int a = stack_a->first->num;
    int b = stack_a->first->next->num;
    int c = stack_a->last->num;

    if (a < b && b < c)
        return;
    else if (a < c && c < b)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (b < a && a < c)
        sa(stack_a);
    else if (b < c && c < a)
        ra(stack_a);
    else if (c < a && a < b)
        rra(stack_a);
    else if (c < b && b < a)
    {
        sa(stack_a);
        rra(stack_a);
    }
}


int get_min_index(t_stack *stack)
{
    t_node *current;
    int min_value;
    int min_index;
    int i;

    if (!stack || stack->size == 0)
        return -1; // Comprobación de seguridad al principio.

    current = stack->first;
    min_value = current->num;
    min_index = 0;
    i = 0;

    while (current)
    {
        if (current->num < min_value)
        {
            min_value = current->num;
            min_index = i;
        }
        current = current->next;
        i++;
    }
    return min_index;
}
void push_min_to_b(t_stack *a, t_stack *b)
{
    int min_pos;
    int i;

    min_pos = get_min_index(a);
    if (min_pos <= a->size / 2)
    {
        i = 0;
        while (i < min_pos)
        {
            ra(a);
            i++;
        }
    }
    else
    {
        i = 0;
        while (i < a->size - min_pos)
        {
            rra(a);
            i++;
        }
    }
    pb(a, b);
}

void order_five_numbers(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_a->size > 3)
    {
        push_min_to_b(stack_a, stack_b);
    }
    order_three_numbers(stack_a);

    while (stack_b->size > 0)
        pa(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	(void)argc;
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		exit_n_error("Error\n", 1);
	parse_arguments(argv, stack_a);
	order_five_numbers(stack_a, stack_b);	
	return (0);            
}
