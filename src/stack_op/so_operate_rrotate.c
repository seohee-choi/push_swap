#include "stack_op.h"

bool				so_rra(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_reverse_rotate_stack(&(*two_stacks)->a_top);
	
	print_ps_node_list((*two_stacks)->a_top);
	write(1, "---a---\n", 8);
	
	return true;
}

bool				so_rrb(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_reverse_rotate_stack(&(*two_stacks)->b_top);
	return true;
}

bool				so_rrr(void)
{
	so_rra();
	so_rrb();
	return true;
}