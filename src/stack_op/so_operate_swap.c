/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_operate_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:39:32 by seohchoi          #+#    #+#             */
/*   Updated: 2021/03/29 17:41:49 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

int	so_sa(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_swap_stack(&(*two_stacks)->a_top);
	return (true);
}

int	so_sb(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_swap_stack(&(*two_stacks)->b_top);
	return (true);
}

int	so_ss(void)
{
	so_sa();
	so_sb();
	return (true);
}
