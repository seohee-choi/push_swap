/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_set_two_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:05:03 by jolim             #+#    #+#             */
/*   Updated: 2021/03/18 17:39:33 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

t_two_stacks	**get_two_stacks(void)
{
	static t_two_stacks	*two_stacks = NULL;

	return (&two_stacks);
}

void	set_two_stacks(t_two_stacks *two_stacks)
{
	t_two_stacks	**stack_setting;

	stack_setting = get_two_stacks();
	*stack_setting = two_stacks;
}
