/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_size_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:21:02 by jolim             #+#    #+#             */
/*   Updated: 2021/03/29 11:36:22 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_key(int list[], int value)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (list[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

// 5 4 1 2 3
// 4 5 1 2 3
// 5 4 1 3 2
// 5 2 1 3 4
// 3 1 2 5 4

static int	ps_sort_size_five_second(int list[])
{
	int				i;
	int				pb_times;
	t_two_stacks	*two_stacks;

	two_stacks = *get_two_stacks();
	i = 0;
	pb_times = 0;
	while (i < 5 && pb_times < 2)
	{
		if (get_key(list, two_stacks->a_top->element) > 2)
			pb_times += ps_register_operation(so_pb);
		else
			ps_register_operation(so_ra);
		i++;
	}
	ps_sort_below_three(2, STACK_B);
	ps_operate_n_times(2, so_ra);
	ps_sort_below_three(3, STACK_A);
	return (0);
}

int	ps_sort_size_five(int list[])
{
	t_two_stacks	*two_stacks;

	two_stacks = *get_two_stacks();
	if (get_key(list, two_stacks->a_top->element) >= 3 && \
	get_key(list, two_stacks->a_top->down_node->element >= 3))
		ps_sort_size_five_second(list);
	if (get_key(list, two_stacks->a_top->element) == 0)
	{
		ps_register_operation(so_pb);
		ps_sort_split_a(list, 1, 5);
		ps_register_operation(so_pa);
	}
	else if (get_key(list, two_stacks->a_top->down_node->element) == 0)
	{
		ps_register_operation(so_sa);
		ps_register_operation(so_pb);
		ps_sort_split_a(list, 1, 5);
		ps_register_operation(so_pa);
	}
	else
		ps_sort_split_a_init(list, 0, 5);
	return (0);
}
