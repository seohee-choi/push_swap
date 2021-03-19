/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simulator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:15:23 by jolim             #+#    #+#             */
/*   Updated: 2021/03/19 16:59:0 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** bottom has to be bigger than top.
*/

void	ps_operate_n_times(int n, bool (*op)(void))
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_print_operate(op);
		i++;
	}
	return ;
}

int	ps_sort_a_to_b(int list[], int top, int bottom)
{
	t_two_stacks	*two_stacks;
	int				n_ra;
	int				n_rb;
	int				i;

	if (bottom - top < 3)
		return(ps_sort_below_three(two_stacks, bottom - top, STACK_A));
	n_ra = 0;
	n_rb = 0;
	i = 0;
	two_stacks = *get_two_stacks();
	while (i < bottom - top + 1)
	{
		if (two_stacks->a_top->element >= list[pivot_small(top, bottom)] && \
		two_stacks->a_top->element < list[pivot_big(top, bottom)])
			n_ra += ps_print_operate(so_ra); // 2
		else
		{
			ps_print_operate(so_pb); // 3 + 1
			if (two_stacks->b_top->element <= list[pivot_small(top, bottom)])
				n_rb += ps_print_operate(so_rb); // 1
		}
		i++;
	}
	ps_sort_b_to_a(list, pivot_big(top, bottom) + 1, bottom); // sort 3 from b to a
	ps_operate_n_times(min_num(n_ra, n_rb), so_rrr); // 1, 2 to top rrr
	if (n_ra > n_rb)
		ps_print_operate(so_rra);
	else if (n_ra < n_rb)
		ps_print_operate(so_rrb);
	ps_operate_n_times(n_ra, so_pb); // 2 from a to b
	ps_sort_b_to_a(list, pivot_small(top, bottom) + 1, pivot_big(top, bottom));
	ps_sort_b_to_a(list, top, pivot_small(top, bottom));
}

void	ps_sort_b_to_a(int list[], int top, int bottom)
{
	int	pivot_big;
	int	pivot_small;
	int i;

	ps_choose_pivots(top, bottom, &pivot_big, &pivot_small);
	i = 0;
	while (i < bottom - top)
	{
		if (two_stacks->b_top > pivot_big)
			ps_print_operate(so_rb());
		else
		{
			ps_print_operate(so_pa());
			if (two_stacks->a_top < pivot_small)
				ps_print_operate(so_ra());
		}
		i++;
	}
}