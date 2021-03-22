/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_operate_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:02:00 by seohchoi          #+#    #+#             */
/*   Updated: 2021/03/22 18:02:28 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

bool	so_ra(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_rotate_stack(&(*two_stacks)->a_top);
	return (true);
}

bool	so_rb(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_rotate_stack(&(*two_stacks)->b_top);
	return (true);
}

bool	so_rr(void)
{
	so_ra();
	so_rb();
	return (true);
}
