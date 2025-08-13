/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:11:42 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/13 18:56:31 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    }
    return (0);
}
// HAY QUE VIGILAR LOS CASOS DE 4 NUMEROS, COMPLETAR EL MAIN, EL .H ACTUALIZAR EL MAKEFILE, CONTROL DE ERRORES Y LIMPIEZA DE MEMORIA