/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:11:42 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/05 18:40:04 by ridoming         ###   ########.fr       */
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
	if (ft_atoi(str) > INT_MAX)
	{
		//cleanup function
		exit_n_error("Error\n", 1);
	}
	
}

void	parse_arguments(char **argv, t_stack *stack)
{
    int i;
	
	i = 0;
	while (argv[i])
	{
		check_number(argv[i], stack);
		if (argv[0])
		{
			// 1. create node 
			// 2. ponerlo como el last
			stack->last;
		}
		else 
		{
			// 1. create node 
			// 2. ponerlo como primero en el stack
			stack->first;
		}
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
