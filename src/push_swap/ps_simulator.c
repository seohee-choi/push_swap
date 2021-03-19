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
/*
int	ps_sort_a_to_a(int list[], int top, int bottom)
{
	t_two_stacks	*two_stacks;
	int				n_ra;
	int				n_rb;
	int				i;

	if (bottom - top < 3)
		return (ps_sort_below_three(bottom - top, A_TO_A));
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
	ps_sort_b_to_a(list, pivot_big(top, bottom) + 1, bottom); // sort 3 from b top to a top
	ps_operate_n_times(min_num(n_ra, n_rb), so_rrr); // 1, 2 to top rrr
	if (n_ra > n_rb)
		ps_print_operate(so_rra);
	else if (n_ra < n_rb)
		ps_print_operate(so_rrb);
	ps_sort_a_to_a(list, pivot_small(top, bottom) + 1, pivot_big(top, bottom));
	ps_sort_b_to_a(list, top, pivot_small(top, bottom));
}
*/

void	ps_split_a_third(int big_pivot_value, int small_pivot_value, \
int *n_ra, int *n_rb)
{
	t_two_stacks	*two_stacks;

	two_stacks = *get_two_stacks();
	if (two_stacks->a_top->element > big_pivot_value)
		*n_ra += ps_print_operate(so_ra); // 3
	else
	{
		ps_print_operate(so_pb); // 2 + 1
		if (two_stacks->b_top->element > small_pivot_value)
			*n_rb += ps_print_operate(so_rb); // 2
	}
}

int	ps_sort_split_a(int list[], int top, int bottom)
{
	int				n_ra;
	int				n_rb;
	int				i;

	if (bottom - top < 3)
		return(ps_sort_below_three(two_stacks, bottom - top, STACK_A));
	n_ra = 0;
	n_rb = 0;
	i = -1;
	two_stacks = *get_two_stacks();
	while (++i < bottom - top + 1)
		ps_split_a_third(list[pivot_big(top, bottom)], \
		list[pivot_small(top, bottom)], &n_ra, &n_rb);
	ps_operate_n_times(min_num(n_ra, n_rb), so_rrr); // 1, 2 to top rrr
	if (n_ra > n_rb)
		ps_print_operate(so_rra);
	else if (n_ra < n_rb)
		ps_print_operate(so_rrb);
	ps_sort_split_a(list, pivot_big(top, bottom) + 1, bottom); // sort 3 from a to b
	ps_sort_split_b(list, pivot_small(top, bottom) + 1, pivot_big(top, bottom)); // sort 2 from b to a
	ps_sort_split_b(list, top, pivot_small(top, bottom)); // sort 1 from a to b
}

void	ps_split_b_third(int big_pivot_value, int small_pivot_value, \
int *n_ra, int *n_rb)
{
	t_two_stacks	*two_stacks;

	two_stacks = *get_two_stacks();
	if (two_stacks->b_top->element <= small_pivot_value)
		*n_ra += ps_print_operate(so_ra); // 1
	else
	{
		ps_print_operate(so_pb); // 3 + 2
		if (two_stacks->a_top->element <= big_pivot_value)
			*n_rb += ps_print_operate(so_rb); // 2
	}
}

void	ps_sort_split_b(int list[], int top, int bottom)
{
	t_two_stacks	*two_stacks;
	int				n_ra;
	int				n_rb;
	int				i;

	if (bottom - top < 3)
		return (ps_sort_below_three(two_stacks, bottom - top, STACK_B));
	n_ra = 0;
	n_rb = 0;
	i = 0;
	while (i < bottom - top + 1)
	{
		if (two)
	}
}