/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_operate_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:39:32 by seohchoi          #+#    #+#             */
/*   Updated: 2021/03/29 17:41:49 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

int	so_pa(void)
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

int	so_pb(void)
{
	t_two_stacks	**two_stacks;
	t_ps_node		*node_taken;

	two_stacks = get_two_stacks();
	node_taken = so_pop_stack(&(*two_stacks)->a_top);
	if (!node_taken)
		return (true);
	so_push_stack(&(*two_stacks)->b_top, node_taken);
	return (true);
}
