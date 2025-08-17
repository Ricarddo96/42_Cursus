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