/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:54:47 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/12 16:53:42 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int get_node_index(t_node *node, t_stack *stack)
{
    int index;
    t_node *i_node;
    
    i_node = stack->first;
    index = 0;
    while (i_node->num != node->num)
    {
        i_node = i_node->next;
        index++;
    }
    return(index);
}

t_node *get_biggest_node(t_stack *stack)
{
    t_node *biggest_node;
    t_node *i_node;
    
    biggest_node = stack->first;
    i_node = stack->first;
    while (i_node)
    {
        if (i_node->num > biggest_node->num)
        {
            biggest_node = i_node;
        }
        i_node = i_node->next;
    }
    return (biggest_node);
}

t_node *get_closest_smaller_node(int num, t_stack *stack_b)
{
    t_node *i_node;
    t_node *closest_smaller;

    closest_smaller = NULL;
    i_node = stack_b->first;
    
    while (i_node)
    {
        if (i_node->num < num)
        {
            if (closest_smaller == NULL || i_node->num > closest_smaller->num)
            {
                closest_smaller = i_node;
            }
        }
        i_node = i_node->next;
    }
    return closest_smaller;
}

t_node *get_target_node(t_node *node, t_stack *stack_b)
{
    t_node *target_node;

    target_node = get_closest_smaller_node(node->num, stack_b);
    if (!target_node)
        target_node = get_biggest_node(stack_b);
    return (target_node);
}

int calculate_cost(t_node *actual_node, t_stack *stack_a, t_stack *stack_b)
{
    int cost_a;
    int cost_b;
    int index_a;
    int index_b;
    int dir_a;
    int dir_b;
    int total_cost;
    
    cost_a = 0;
    cost_b = 0;
    index_a = get_node_index(actual_node, stack_a);
    index_b = get_node_index(get_target_node(actual_node, stack_b), stack_b);
    if (index_a > (stack_a->size / 2))
        cost_a = stack_a->size - index_a;
    else
        cost_a = index_a;
    if (index_b > (stack_b->size / 2))
        cost_b = stack_b->size - index_b;
    else
        cost_b = index_b;
    total_cost = cost_a + cost_b + 1;
    return (total_cost);
}

///// PROXIMOS PASOS : AJUSTAR CALCULATE COST PARA QUE CALCULE SI LE VIENE MEJOR HACER RA O RRA Y CALCULAR EL COSTE EN BASE A ESO