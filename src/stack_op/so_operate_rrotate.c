/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_operate_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:39:31 by seohchoi          #+#    #+#             */
/*   Updated: 2021/03/22 21:39:34 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

bool	so_rra(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_reverse_rotate_stack(&(*two_stacks)->a_top);
	return (true);
}

bool	so_rrb(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_reverse_rotate_stack(&(*two_stacks)->b_top);
	return (true);
}

bool	so_rrr(void)
{
	so_rra();
	so_rrb();
	return (true);
}
