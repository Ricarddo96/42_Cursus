#include "push_swap.h"

void push(t_stack *stack_receive, t_stack *stack_send)
{
	t_node *node_to_push;

	if (stack_send->size < 1)
		return;
	node_to_push = stack_send->first;
	stack_send->first = node_to_push->next;
	if (stack_send->first)
		stack_send->first->prev = NULL;
	stack_send->size--;
	if (stack_receive->size == 0)
	{
		stack_receive->first = node_to_push;
		stack_receive->first->next = NULL;
		stack_receive->first->prev = NULL;
	}
	else
	{
		node_to_push->next = stack_receive->first;
		stack_receive->first->prev = node_to_push;
		stack_receive->first = node_to_push;
	}
	stack_receive->size++;
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}