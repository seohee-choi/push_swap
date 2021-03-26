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

static void	ps_split_a_third(int big_pivot_value, int small_pivot_value, \
int *n_ra, int *n_rb)
{
	t_two_stacks	*two_stacks;

	two_stacks = *get_two_stacks();
	if (two_stacks->a_top->element >= big_pivot_value)
		*n_ra += ps_register_operation(so_ra);
	else
	{
		ps_register_operation(so_pb);
		if (two_stacks->b_top->element >= small_pivot_value)
		{
			(*n_rb)++;
			if (two_stacks->b_top->down_node != two_stacks->b_top)
				ps_register_operation(so_rb);
		}
	}
}

void	ps_sort_split_a_init(int list[], int top, int bottom)
{
	int				i;
	t_two_stacks	*two_stacks;

	two_stacks = *get_two_stacks();
	if (bottom - top <= 3)
	{
		ps_sort_below_three(bottom - top, STACK_A);
		return ;
	}
	i = -1;
	while (++i < bottom - top)
	{
		if (two_stacks->a_top->element >= list[pivot_big(top, bottom)])
			ps_register_operation(so_ra);
		else
		{
			ps_register_operation(so_pb);
			if (two_stacks->b_top->element < list[pivot_small(top, bottom)])
			{
				if (two_stacks->b_top->down_node != two_stacks->b_top)
					ps_register_operation(so_rb);
			}
		}
	}
	ps_sort_split_a(list, pivot_big(top, bottom), bottom);
	ps_sort_split_b(list, pivot_small(top, bottom), pivot_big(top, bottom));
	ps_sort_split_b(list, top, pivot_small(top, bottom));
}

void	ps_sort_split_a(int list[], int top, int bottom)
{
	int				n_ra;
	int				n_rb;
	int				i;

	if (bottom - top <= 3)
	{
		ps_sort_below_three(bottom - top, STACK_A);
		return ;
	}
	n_ra = 0;
	n_rb = 0;
	i = -1;
	while (++i < bottom - top)
		ps_split_a_third(list[pivot_big(top, bottom)], \
		list[pivot_small(top, bottom)], &n_ra, &n_rb);
	ps_operate_n_times(min_num(n_ra, n_rb), so_rrr);
	if (n_ra > n_rb)
		ps_register_operation(so_rra);
	else if (n_ra < n_rb)
		ps_register_operation(so_rrb);
	ps_sort_split_a(list, pivot_big(top, bottom), bottom);
	ps_sort_split_b(list, pivot_small(top, bottom), pivot_big(top, bottom));
	ps_sort_split_b(list, top, pivot_small(top, bottom));
}

static void	ps_split_b_third(int big_pivot_value, int small_pivot_value, \
int *n_ra, int *n_rb)
{
	t_two_stacks	*two_stacks;

	two_stacks = *get_two_stacks();
	if (two_stacks->b_top->element < small_pivot_value)
	{
		*n_rb += ps_register_operation(so_rb);
	}
	else
	{
		ps_register_operation(so_pa);
		if (two_stacks->a_top->element < big_pivot_value)
		{
			(*n_ra)++;
			if (two_stacks->a_top->down_node != two_stacks->a_top)
				ps_register_operation(so_ra);
		}
	}
}

void	ps_sort_split_b(int list[], int top, int bottom)
{
	int				n_ra;
	int				n_rb;
	int				i;

	if (bottom - top < 3)
	{
		ps_sort_below_three(bottom - top, STACK_B);
		return ;
	}
	n_ra = 0;
	n_rb = 0;
	i = -1;
	while (++i < bottom - top)
		ps_split_b_third(list[pivot_big(top, bottom)], \
		list[pivot_small(top, bottom)], &n_ra, &n_rb);
	ps_sort_split_a(list, pivot_big(top, bottom), bottom);
	ps_operate_n_times(min_num(n_ra, n_rb), so_rrr);
	if (n_ra > n_rb)
		ps_register_operation(so_rra);
	else if (n_ra < n_rb)
		ps_register_operation(so_rrb);
	ps_sort_split_a(list, pivot_small(top, bottom), pivot_big(top, bottom));
	ps_sort_split_b(list, top, pivot_small(top, bottom));
}
