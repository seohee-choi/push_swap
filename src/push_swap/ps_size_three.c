/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_size_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:00:20 by jolim             #+#    #+#             */
/*   Updated: 2021/03/19 23:46:51 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 123
// 132 sa ra
// 321 sa rra
// 312 ra
// 213 sa
// 231 rra

static int	min_node(t_ps_node *top, t_ps_node *mid, t_ps_node *btm)
{
	if (top->element > mid->element)
	{
		if (mid->element > btm->element)
			return (BTM);
		else
			return (MID);
	}
	if (top->element > btm->element)
		return (BTM);
	else
		return (TOP);
}

static int	max_node(t_ps_node *top, t_ps_node *mid, t_ps_node *btm)
{
	if (top->element > mid->element)
	{
		if (top->element > btm->element)
			return (TOP);
		else
			return (BTM);
	}
	if (mid->element > btm->element)
		return (MID);
	else
		return (BTM);
}

int	ps_sort_size_three(void)
{
	t_two_stacks	*two_stacks;
	t_ps_node		*top;
	t_ps_node		*mid;
	t_ps_node		*btm;
	char			order[3];

	two_stacks = *get_two_stacks();
	top = two_stacks->a_top;
	mid = top->down_node;
	btm = mid->down_node;
	order[min_node(top, mid, btm)] = '1';
	order[3 - max_node(top, mid, btm) - min_node(top, mid, btm)] = '2';
	order[max_node(top, mid, btm)] = '3';
	if (!ft_strncmp(order, "123", 3))
		return (0);
	if (!ft_strncmp(order, "312", 3))
		return (ps_print_operate(so_ra));
	if (!ft_strncmp(order, "213", 3))
		return (ps_print_operate(so_sa));
	if (!ft_strncmp(order, "231", 3))
		return (ps_print_operate(so_rra));
	ps_print_operate(so_sa);
	if (!ft_strncmp(order, "132", 3))
		return (ps_print_operate(so_ra));
	return(ps_print_operate(so_rra));
}