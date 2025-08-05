/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:53:37 by ridoming          #+#    #+#             */
/*   Updated: 2025/08/04 19:11:20 by ridoming         ###   ########.fr       */
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
    struct s_node *prev;
    int num;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *first;
    int size;
    t_node *last;
} t_stack;

#endif