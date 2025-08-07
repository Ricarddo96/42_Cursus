/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:11:42 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/07 18:04:42 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void exit_n_error(char *msg, int mod)
{
	if (mod == 1)
	{
		write(2, &msg, ft_strlen(msg));
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
	while (i < stack->size)
	{
		if (num == current_node->num)
			exit_n_error("Error\n", 1);
		current_node = current_node->prev;
		i++;
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
			current_node->next = stack->first;
			stack->first->prev = current_node;
			stack->first = current_node;
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
	
	// CASO A, B, C
	if (a < b && b < c)
		return;
	// CASO A, C, B
	else if (a < c && c < b)
    {
        sa(stack_a);
        ra(stack_a);
    }
    // CASO: B, A, C
    else if (b < a && a < c)
        sa(stack_a);
    // CASO: B, C, A
    else if (b < c && c < a)
        rra(stack_a);
    // CASO: C, A, B
    else if (c < a && a < b)
        ra(stack_a);
    // CASO: C, B, A
    else if (c < b && b < a)
    {
        sa(stack_a);
        rra(stack_a);
    }
}

int check_lower_of_stack(t_stack *a, t_stack *b)
{
	int i = 0;
	int num = a->first->num;
	t_node *next_num = a->first->next;
	
	while (i < a->size)
	{
		if (next_num->num < num)
		{
			num = next_num;
		}
		next_num = next_num->next;
		i++;
	}
	// falta saber la posicion del nodo para saber cuantos ra
	
}

void order_five_numbers(t_stack *stack_a, t_stack *stack_b)
{
	
		
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
	order_three_numbers(stack_a);	
	return (0);            
}
