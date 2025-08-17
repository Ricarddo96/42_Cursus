/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:17:16 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/17 16:26:33 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *next;

    if (!stack)
        return;
    current = stack->first;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

void exit_n_error(char *msg, t_stack *stack_a, t_stack *stack_b)
{
    write(2, msg, ft_strlen(msg));
    if (stack_a)
        free_stack(stack_a);
    if (stack_b)
        free_stack(stack_b);
    exit(EXIT_FAILURE);    
}




void final_sort(t_stack *stack_a)
{
    t_node *min_node;
    int idx;
    
    min_node = get_smallest_node(stack_a);
    idx = get_node_index(min_node, stack_a);
    if (idx <= stack_a->size / 2)
    {
        while (idx-- > 0)
            ra(stack_a);
    }
    else
    {
        int steps = stack_a->size - idx;
        while (steps-- > 0)
            rra(stack_a);
    }
}
