/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_operate_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:39:32 by seohchoi          #+#    #+#             */
/*   Updated: 2021/03/18 20:34:43 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

bool	so_sa(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_swap_stack(&(*two_stacks)->a_top);
	return (true);
}

bool	so_sb(void)
{
	t_two_stacks	**two_stacks;

	two_stacks = get_two_stacks();
	so_swap_stack(&(*two_stacks)->b_top);
	return (true);
}

bool				so_ss(void)
{
	so_sa();
	so_sb();
	return (true);
}