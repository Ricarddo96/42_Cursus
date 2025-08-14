
#include "../push_swap.h"

void swap_nodes(t_stack *stack)
{
    t_node *node_1;
    t_node *node_2;

    if (stack->size < 2)
        return;
    node_1 = stack->first;
    node_2 = node_1->next;

    node_1->next = node_2->next;
    if (node_1->next)
        node_1->next->prev = node_1;
    node_2->prev = NULL;
    node_2->next = node_1;
    node_1->prev = node_2;
    stack->first = node_2;
    if (stack->size == 2)
        stack->last = node_1;
}

void	sa(t_stack *stack_a)
{
	swap_nodes(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	swap_nodes(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	write(1, "ss\n", 3);
}