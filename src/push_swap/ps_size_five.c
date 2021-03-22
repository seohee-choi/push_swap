/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_size_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:21:02 by jolim             #+#    #+#             */
/*   Updated: 2021/03/22 18:00:57 by jolim            ###   ########.fr       */
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

int	ps_sort_size_five(int list[])
{
	t_two_stacks	*two_stacks;

	two_stacks = *get_two_stacks();
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
		ps_sort_split_a(list, 0, 5);
	return (0);
}
