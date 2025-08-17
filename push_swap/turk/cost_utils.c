/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:24:12 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/17 16:31:42 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int get_node_index(t_node *node, t_stack *stack)
{
    int index;
    t_node *i_node;

    if (!node || !stack)
        return (-1);
    i_node = stack->first;
    index = 0;
    while (i_node)
    {
        if (i_node == node)
            return index;
        i_node = i_node->next;
        index++;
    }
    return (-1);
}

t_node *get_smallest_node(t_stack *stack)
{
    t_node *smallest_node;
    t_node *i_node;

    if (!stack || stack->size == 0 || !stack->first)
        return NULL;
    smallest_node = stack->first;
    i_node = stack->first->next;
    while (i_node)
    {
        if (i_node->num < smallest_node->num)
            smallest_node = i_node;
        i_node = i_node->next;
    }
    return (smallest_node);
}

t_node *get_biggest_node(t_stack *stack)
{
    t_node *biggest_node;
    t_node *i_node;

    if (!stack || stack->size == 0 || !stack->first)
        return NULL;
    biggest_node = stack->first;
    i_node = stack->first->next;
    while (i_node)
    {
        if (i_node->num > biggest_node->num)
            biggest_node = i_node;
        i_node = i_node->next;
    }
    return (biggest_node);
}
