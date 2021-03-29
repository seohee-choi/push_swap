/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simulator_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:04:31 by jolim             #+#    #+#             */
/*   Updated: 2021/03/29 15:51:37 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pivot_big(int top, int bottom)
{
	return (top + 2 * (bottom - top) / 3);
}

int		pivot_small(int top, int bottom)
{
	return (top + (bottom - top) / 3);
}

int		max_num(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		min_num(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	ps_operate_n_times(int n, bool (*op)(void))
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_register_operation(op);
		i++;
	}
	return ;
}
