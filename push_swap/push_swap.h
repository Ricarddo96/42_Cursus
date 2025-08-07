/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:53:37 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/07 17:25:11 by ridoming         ###   ########.fr       */
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

void    exit_n_error(char *msg, int mod);
int     check_number(char *str, t_stack *stack);
t_node  *create_node(int num);
void	parse_arguments(char **argv, t_stack *stack);
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