/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:11:42 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/06 16:51:52 by ridoming         ###   ########.fr       */
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
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			//cleanup function
			exit_n_error("Error\n", 1);
		}
		i++;
	}
	if (ft_atol(str) > INT_MAX)
	{
		//cleanup function
		exit_n_error("Error\n", 1);
	}
	
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
			stack->first = current_node;
			stack->last->prev;
		}
		stack->size++;
		i++;	
	}
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
// 1 numero de args correcto 
// parseo de los argumentos e ir metiendolos al stack a
	parse_arguments(argv, stack_a);
	return (0);            
}
