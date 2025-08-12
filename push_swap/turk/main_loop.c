/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:47:44 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/12 19:14:47 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void order_cheapest_node(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
    // AHORA HAY QUE HACER LA LOGICA PARA DETERMINAR CUANDO ES MAS EFICIENTE UTILIZAR RR O RRR Y HASTA DONDE PORQUE ESTA 
    // FUNCION ORDENA PERO SOLO CON RA RRA RB RRB ADEMAS TIENE ERRORES EN LA LOGICA
    // DESPUES DE ESTO LO QUE QUEDA ES AFINAR EL MAIN, VER CASOS ESPECIALES COMO EL CASO DE LOS 4 Y LIMPIAR LA MEMORIA
    int a_pos;
    int b_pos;
    int i = 0;
    
    a_pos = get_node_index(node, stack_a);
    b_pos = get_node_index(get_target_node(node, stack_b), stack_b); 
    if (a_pos < (stack_a->size / 2))
    {
        while (i < a_pos)
        {
            ra(stack_a);
            i++;
        }
    }
    else
    {
        while (i < (stack_a->size - a_pos))
        {
            rra(stack_a);
            i++;
        }   
    }
    i = 0;
    
    if (b_pos < (stack_b->size / 2))
    {
        while (i < b_pos)
        {
            rb(stack_a);
            i++;
        }
    }
    else
    {
        while (i < (stack_b->size - b_pos))
        {
            rrb(stack_a);
            i++;
        }   
    }
    pb(stack_a, stack_b);
}

void main_loop(t_stack *a, t_stack *b, t_cost c)
{
    t_node *i_nd;
    t_node *cheap;

    i_nd = a->first;
    cheap = a->first;
    while (a->size > 3)
    {
        while (i_nd)
        {
            if (calculate_cost(i_nd, a, b, c) < calculate_cost(cheap, a, b, c))
            {
                cheap = i_nd;
            }
            i_nd = i_nd->next;
        }
        order_cheapest_node(cheap, a, b);
    }
}
