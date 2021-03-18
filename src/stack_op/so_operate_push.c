/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_operate_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:39:32 by seohchoi          #+#    #+#             */
/*   Updated: 2021/03/18 20:01:38 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

bool	so_pa(void)
{
	t_two_stacks	**two_stacks;
	t_ps_node		*node_taken;

	two_stacks = get_two_stacks();
	node_taken = so_pop_stack(&(*two_stacks)->b_top);
	if (!node_taken)
		return (true);
	so_push_stack(&(*two_stacks)->a_top, node_taken);
	return (true);
}

bool	so_pb(void)
{
	t_two_stacks	**two_stacks;
	t_ps_node		*node_taken;

	two_stacks = get_two_stacks();
	node_taken = so_pop_stack(&(*two_stacks)->a_top);
	if (!node_taken)
		return (true);
	so_push_stack(&(*two_stacks)->b_top, node_taken);
	so_pop_stack(&(*two_stacks)->a_top);
	return (true);
}
