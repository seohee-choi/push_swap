/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_operate_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:39:31 by seohchoi          #+#    #+#             */
/*   Updated: 2021/03/29 17:41:49 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

int	so_rra(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_reverse_rotate_stack(&(*two_stacks)->a_top);
	return (true);
}

int	so_rrb(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_reverse_rotate_stack(&(*two_stacks)->b_top);
	return (true);
}

int	so_rrr(void)
{
	so_rra();
	so_rrb();
	return (true);
}
