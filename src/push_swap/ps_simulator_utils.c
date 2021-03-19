/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simulator_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:04:31 by jolim             #+#    #+#             */
/*   Updated: 2021/03/19 17:15:23 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot_big(int top, int bottom)
{
	return (top + 2 * (bottom - top) / 3);
}

int	pivot_small(int top, int bottom)
{
	return (top + (bottom - top) / 3);
}

int	max_num(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min_num(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
