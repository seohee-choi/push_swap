#include "stack_op.h"

bool				so_ra(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_rotate_stack(&(*two_stacks)->a_top);
	return true;
}

bool				so_rb(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_rotate_stack(&(*two_stacks)->b_top);
	return true;
}

bool				so_rr(void)
{
	so_ra();
	so_rb();
	return true;
}