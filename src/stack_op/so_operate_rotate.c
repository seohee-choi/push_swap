/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_operate_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:02:00 by seohchoi          #+#    #+#             */
/*   Updated: 2021/03/29 17:41:49 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

int	so_ra(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_rotate_stack(&(*two_stacks)->a_top);
	return (true);
}

int	so_rb(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_rotate_stack(&(*two_stacks)->b_top);
	return (true);
}

int	so_rr(void)
{
	so_ra();
	so_rb();
	return (true);
}
