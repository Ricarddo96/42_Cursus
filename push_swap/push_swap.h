/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:53:37 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/14 18:20:58 by ridoming         ###   ########.fr       */
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

typedef struct s_cost
{
    int     index_a;
	int     index_b;
	int     ra_rb;
	int     rra_rrb;
	int     ra_rrb;
	int     rra_rb;
} t_cost;

int get_safe_index(t_node *node, t_stack *stack);
void order_three_numbers(t_stack *stack_a);
void	parse_arguments(char **argv, t_stack *stack_a, t_stack *stack_b);
void order_three_numbers(t_stack *stack_a);
void free_stack(t_stack *stack);
void exit_n_error(char *msg, t_stack *stack_a, t_stack *stack_b);
int check_number(char *str, t_stack *stack);
t_node *create_node(int num, t_stack *stack_a, t_stack *stack_b);
void order_two_numbers(t_stack *stack_a);
int get_node_index(t_node *node, t_stack *stack);
t_node *get_smallest_node(t_stack *stack);
t_node *get_biggest_node(t_stack *stack);
t_node *get_closest_smaller_node(int num, t_stack *stack_b);
void final_sort(t_stack *stack_a);
t_node *get_target_node(t_node *node, t_stack *stack_b);
int	calculate_cost(t_node *node, t_stack *stack_a, t_stack *stack_b, t_cost *c);
void a_up_b_up(int a_idx, int b_idx, t_stack *stack_a, t_stack *stack_b);
void a_down_b_down(int a_idx, int b_idx, t_stack *stack_a, t_stack *stack_b);
void a_up_b_down(int a_idx, int b_idx, t_stack *stack_a, t_stack *stack_b);
void a_down_b_up(int a_idx, int b_idx, t_stack *stack_a, t_stack *stack_b);
void order_cheapest_node(t_node *node, t_stack *a, t_stack *b);
void main_loop(t_stack *a, t_stack *b);
void push(t_stack *stack_receive, t_stack *stack_send);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);
void reverse_rotate(t_stack *stack);
void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);
void rotate(t_stack *stack);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
void swap_nodes(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

#endif