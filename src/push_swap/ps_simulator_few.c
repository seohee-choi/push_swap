/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simulator_few.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:05:47 by jolim             #+#    #+#             */
/*   Updated: 2021/03/19 21:16:17 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

2#include "push_swap.h"

int	ps_sort_below_three(t_two_stacks *two_stacks, int num, int stack_name)
{
	if (num == 3)
		return (ps_sort_three(two_stacks, stack_name));
	if (num == 2)
		return (ps_sort_two(two_stacks, stack_name));
	else
	{
		if (stack_name == STACK_A)
			return (ps_print_operate(so_pb));
		else if (stack_name == STACK_B)
			return (ps_print_operate(so_pa));
	}
}

int	ps_sort_three(t_two_stacks *two_stacks, int stack_name)
{

}

int	ps_sort_two(t_two_stacks *two_stacks, int stack_name)
{
	if (stack_name = STACK_A)
	{
		if (two_stacks->a_top->element > two_stacks->a_top->down_node->element)
			return (ps_print_operate(so_sa));
		else
			return (1);
	}
	if (stack_name = STACK_B)
	{
		if (two_stacks->b_top->element < two_stacks->b_top->down_node->element)
			ps_print_operate(so_sb);
		ps_print_operate(so_pa);
		return (ps_print_operate(so_pa));
	}
}