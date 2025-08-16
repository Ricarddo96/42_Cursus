/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:11:42 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/16 18:40:32 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_safe_index(t_node *node, t_stack *stack)
{
    int idx;

    if (!node || !stack)
        return 0;
    idx = get_node_index(node, stack);
    if (idx < 0)
        return 0;
    return (idx);
}

void	parse_arguments(char **argv, t_stack *stack_a, t_stack *stack_b)
{
	t_node *current_node;
    int i;
	
	i = 1;
	stack_a->first = NULL;
	stack_a->last = NULL;
	stack_a->size = 0;
	while (argv[i])
	{
		check_number(argv[i], stack_a);
		current_node = create_node(ft_atol(argv[i]), stack_a, stack_b);
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
		exit_n_error("Error\n", stack_a, stack_b);
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


//problema, no ordena la pila bien, mirar el caso para 4, y mirar para el caso que nos lo pasan como una string
// vale el error creoo que esta en que no pusheamos de vuelta a A mirando si la hemos pusheado en la posicion correcta, en caso de que no sea asi 
// rotamos hasta encontrar la pposicion correcta en la que puede ser pusheado
// Cómo debería ser la vuelta con Turk
/* 
Mientras b no esté vacío:

Para cada nodo en b, calculas su target en a (el más pequeño mayor que él, o el mínimo si no existe).

Calculas costes (ra, rra, rb, rrb, rr, rrr) para alinear a y b.

Escoges el nodo de b con menor coste.

Haces las rotaciones necesarias.

pa para insertarlo en a.

Cuando b está vacío, haces tu final_sort (rotar a hasta que el mínimo esté arriba).

⚠️ El error concreto en tu código

Tu order_cheapest_node hace pb(a, b) (todavía en la fase de ida).

Pero nunca haces el mismo cálculo al revés (nodo de b → target en a) en la vuelta.

En main simplemente haces while (stack_b->size > 0) pa(...), lo cual ignora totalmente la lógica de posiciones.

 */