#include "../push_swap.h"

void rotate(t_stack *stack)
{
	t_node *first_node;

	if (stack->size < 2)
		return;
	first_node = stack->first;
	first_node->prev = stack->last;
	stack->first = stack->first->next;
	stack->first->prev = NULL;
	first_node->next = NULL;
	stack->last->next = first_node;
	stack->last = first_node;
}
void ra(t_stack *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void rb(t_stack *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}
void rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}