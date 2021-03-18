/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_operate_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:39:32 by seohchoi          #+#    #+#             */
/*   Updated: 2021/03/18 19:27:48 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

bool	so_sa(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	if ((*two_stacks)->a_top->down_node != NULL)
		so_swap_stack(&(*two_stacks)->a_top);

	print_ps_node_list((*two_stacks)->a_top);
	write(1, "---a---\n", 8);
	// print_ps_node_list((*two_stacks)->b_top);
	// write(1, "---b---\n", 8);
	return true;
}

bool	so_sb(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	if ((*two_stacks)->b_top->down_node != NULL)
		so_swap_stack(&(*two_stacks)->b_top);
	return true;
}

bool				so_ss(void)
{
	so_sa();
	so_sb();
	return true;
}