/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simulator_few.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:05:47 by jolim             #+#    #+#             */
/*   Updated: 2021/03/19 18:25:44 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sort_below_three(t_two_stacks *two_stacks, int num, int stack_name)
{
	if (stack_name == STACK_A)
	{
		if (num == 3)
			return (ps_sort_three(two_stacks, STACK_A));
		if (num == 2)
			return (ps_sort_two(two_stacks, STACK_A));
		else
			return (ps_print_operate(so_pb));
	}
	if (num == 3)
		return (ps_sort_three(two_stacks, STACK_B));
	if (num == 2)
		return (ps_sort_two(two_stacks, STACK_B));
	else
		return (ps_print_operate(so_pa));
}

int	ps_sort_three(t_two_stacks *two_stacks, int stack_name)
{
	if (stack_name = STACK_A)
	{

	}
}

int	ps_sort_two(t_two_stacks *two_stacks, int stack_name)
{
	if (stack_name = STACK_A)
	{
		if (two_stacks->a_top->element > two_stacks->a_top->down_node->element)
			ps_print_operate(so_pa)

	}
}