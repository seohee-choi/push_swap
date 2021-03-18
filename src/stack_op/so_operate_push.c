/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_operate_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:39:32 by seohchoi          #+#    #+#             */
/*   Updated: 2021/03/18 18:49:56 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

bool	so_pa(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_push_stack(&(*two_stacks)->a_top, so_pop_stack(&(*two_stacks)->b_top));
	return true;
}

bool	so_pb(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_push_stack(&(*two_stacks)->b_top, so_pop_stack(&(*two_stacks)->a_top));
	so_pop_stack(&(*two_stacks)->a_top);
	return true;
}
