//rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
//rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
//rrr : rra and rrb at the same time.
#include "stack_op.h"

bool				so_rra(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_reverse_rotate_stack((*two_stacks)->a_top);
	return true;
}

bool				so_rrb(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_reverse_rotate_stack((*two_stacks)->b_top);
	return true;
}

bool				so_rrr(void)
{
	so_rra();
	so_rrb();
	return true;
}