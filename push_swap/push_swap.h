/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:53:37 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/11 18:58:10 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdlib.h> 
# include <limits.h>

typedef struct s_node
{
    struct s_node   *prev;
    int             num;
    struct s_node   *next;
} t_node;

typedef struct s_stack
{
    t_node  *first;
    int     size;
    t_node  *last;
} t_stack;

t_node  *create_node(int num);
int     check_number(char *str, t_stack *stack);
int     calculate_cost(t_node *actual_node, t_stack *stack_a, t_stack *stack_b);
void    exit_n_error(char *msg, int mod);
void	parse_arguments(char **argv, t_stack *stack);
void    order_two_numbers(t_stack *stack_a);
void	swap_nodes(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void    push(t_stack *stack_receive, t_stack *stack_send);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);
void    rotate(t_stack *stack);
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    reverse_rotate(t_stack *stack);
void    rra(t_stack *stack_a);
void    rrb(t_stack *stack_b);
void    rrr(t_stack *stack_a, t_stack *stack_b);

void order_three_numbers(t_stack *stack_a);

#endif