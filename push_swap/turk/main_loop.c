/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:47:44 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/14 18:22:06 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void a_up_b_up(int a_idx, int b_idx, t_stack *stack_a, t_stack *stack_b)
{
    while (a_idx > 0 && b_idx > 0)
    {
        rr(stack_a, stack_b);
        a_idx--;
        b_idx--;
    }
    while (a_idx > 0)
    {
        ra(stack_a);
        a_idx--;
    }
    while (b_idx > 0)
    {
        rb(stack_b);
        b_idx--;
    }
}

void a_down_b_down(int a_idx, int b_idx, t_stack *stack_a, t_stack *stack_b)
{
    while (a_idx > 0 && b_idx > 0)
    {
        rrr(stack_a, stack_b);
        a_idx--;
        b_idx--;
    }
    while (a_idx > 0)
    {
        rra(stack_a);
        a_idx--;
    }
    while (b_idx > 0)
    {
        rrb(stack_b);
        b_idx--;
    }
}

void a_up_b_down(int a_idx, int b_idx, t_stack *stack_a, t_stack *stack_b)
{
    while (a_idx > 0)
    {
        ra(stack_a);
        a_idx--;
    }
    while (b_idx > 0)
    {
        rrb(stack_b);
        b_idx--;
    }
}

void a_down_b_up(int a_idx, int b_idx, t_stack *stack_a, t_stack *stack_b)
{
    while (a_idx > 0)
    {
        rra(stack_a);
        a_idx--;
    }
    while (b_idx > 0)
    {
        rb(stack_b);
        b_idx--;
    }
}

void order_cheapest_node(t_node *node, t_stack *a, t_stack *b)
{
    int a_idx;
    int b_idx; 
    t_node *target;

    a_idx = get_safe_index(node, a);
    target = get_target_node(node, b);
    if (!target)
        b_idx = 0;
    else
        b_idx = get_safe_index(target, b);
    if (a_idx <= a->size / 2 && b_idx <= b->size / 2)
        a_up_b_up(a_idx, b_idx, a, b);
    else if (a_idx > a->size / 2 && b_idx > b->size / 2)
        a_down_b_down(a->size - a_idx, b->size - b_idx, a, b);
    else if (a_idx <= a->size / 2 && b_idx > b->size / 2)
        a_up_b_down(a_idx, b->size - b_idx, a, b);
    else
        a_down_b_up(a->size - a_idx, b_idx, a, b);
    pb(a, b);
}

void main_loop(t_stack *a, t_stack *b)
{
    t_node *i_nd;
    t_node *cheap;
    t_cost c;
    int best;
    int cost;

    i_nd = a->first;
    cheap = a->first;

    best = calculate_cost(cheap, a, b, &c);
    while (i_nd)
    {
        cost = calculate_cost(i_nd, a, b, &c);
        if (cost < best)
        {
            best = cost;
            cheap = i_nd;
        }
        i_nd = i_nd->next;
    }
    order_cheapest_node(cheap, a, b);
}
