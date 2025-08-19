/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:54:47 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/19 17:54:32 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node *get_closest_bigger_node(int num, t_stack *stack_a)
{
    t_node *i_node;
    t_node *closest_bigger;

    closest_bigger = NULL;
    i_node = stack_a->first;
    
    while (i_node)
    {
        if (i_node->num > num)
        {
            if (closest_bigger == NULL || i_node->num < closest_bigger->num)
            {
                closest_bigger = i_node;
            }
        }
        i_node = i_node->next;
    }
    return (closest_bigger);
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
    return (closest_smaller);
}


t_node *get_target_node(t_node *node, t_stack *stack, char option)
{
    t_node *target_node;
    
    target_node = NULL;
    if (!node || !stack || stack->size == 0)
        return (NULL);
    if (option == 'B')
    {
        target_node = get_closest_smaller_node(node->num, stack);
        if (!target_node)
            target_node = get_biggest_node(stack);
    }
    else if (option == 'A')
    {
        target_node = get_closest_bigger_node(node->num, stack);
        if (!target_node)
            target_node = get_smallest_node(stack);
    }
    return (target_node);
}

int	calculate_cost_b(t_node *node, t_stack *stack_a, t_stack *stack_b, t_cost *c)
{
    int total;
    
    total = 0;
	c->index_a = get_safe_index(node, stack_a);
	c->index_b = get_safe_index(get_target_node(node, stack_b, 'B'), stack_b);
	c->ra_rb = ft_max(c->index_a, c->index_b);
	c->rra_rrb = ft_max(stack_a->size - c->index_a, stack_b->size - c->index_b);
	c->ra_rrb = c->index_a + (stack_b->size - c->index_b);
	c->rra_rb = (stack_a->size - c->index_a) + c->index_b;
    total = ft_min(ft_min(c->ra_rb, c->rra_rrb), ft_min(c->ra_rrb, c->rra_rb)) + 1;
	return (total);
}

int	calculate_cost_a(t_node *node, t_stack *stack_a, t_stack *stack_b, t_cost *c)
{
    int total;
    
    total = 0;
	c->index_b = get_safe_index(node, stack_b);
	c->index_a = get_safe_index(get_target_node(node, stack_a, 'A'), stack_a);
	c->ra_rb = ft_max(c->index_a, c->index_b);
	c->rra_rrb = ft_max(stack_a->size - c->index_a, stack_b->size - c->index_b);
	c->ra_rrb = c->index_a + (stack_b->size - c->index_b);
	c->rra_rb = (stack_a->size - c->index_a) + c->index_b;
    total = ft_min(ft_min(c->ra_rb, c->rra_rrb), ft_min(c->ra_rrb, c->rra_rb)) + 1;
	return (total);
}
