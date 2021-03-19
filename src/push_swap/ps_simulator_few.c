/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simulator_few.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:05:47 by jolim             #+#    #+#             */
/*   Updated: 2021/03/19 23:46:51 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_sort_two(t_two_stacks *two_stacks, int stack_name)
{
	if (stack_name == STACK_A)
	{
		if (two_stacks->a_top->element > two_stacks->a_top->down_node->element)
			return (ps_print_operate(so_sa));
		return (0);
	}
	if (stack_name == STACK_B)
	{
		if (two_stacks->b_top->element < two_stacks->b_top->down_node->element)
			ps_print_operate(so_sb);
		ps_print_operate(so_pa);
		return (ps_print_operate(so_pa));
	}
	return (1);
}

static int ps_sort_three_a(t_two_stacks *two_stacks)
{
	if (two_stacks->a_top->element == min_num(min_num(two_stacks->a_top->element
	, two_stacks->a_top->down_node->element),
	two_stacks->a_top->down_node->down_node->element))
	{
		ps_print_operate(so_ra);
		ps_sort_two(two_stacks, STACK_A);
		return (ps_print_operate(so_rra));
	}
	else if (two_stacks->a_top->down_node->element == min_num(min_num(two_stacks
	->a_top->element, two_stacks->a_top->down_node->element), two_stacks->a_top
	->down_node->down_node->element))
	{
		ps_print_operate(so_sa);
		ps_print_operate(so_ra);
		ps_sort_two(two_stacks, STACK_A);
		return (ps_print_operate(so_rra));
	}
	ps_sort_two(two_stacks, STACK_A);
	ps_print_operate(so_ra);
	ps_print_operate(so_ra);
	ps_print_operate(so_pb);
	ps_print_operate(so_rra);
	ps_print_operate(so_rra);
	return (ps_print_operate(so_pa));
}

static int	ps_sort_three(t_two_stacks *two_stacks, int stack_name)
{
	if (stack_name == STACK_A)
		return (ps_sort_three_a(two_stacks));
	else if (stack_name == STACK_B)
	{
		if (two_stacks->b_top->element == max_num(max_num(two_stacks->b_top->
		element, two_stacks->b_top->down_node->element), two_stacks->b_top->
		down_node->down_node->element))
			ps_print_operate(so_pa);
		else if (two_stacks->b_top->down_node->element == max_num(
			max_num(two_stacks->b_top->element, two_stacks->b_top->down_node->
			element), two_stacks->b_top->down_node->down_node->element))
		{
			ps_print_operate(so_sb);
			ps_print_operate(so_pa);
		}
		else
		{
			ps_print_operate(so_rb);
			ps_print_operate(so_sb);
			ps_print_operate(so_pa);
			ps_print_operate(so_rrb);
		}
		return (ps_sort_two(two_stacks, STACK_B));
	}
	return (0);
}


int	ps_sort_below_three(int num, int stack_name)
{
	t_two_stacks	*two_stacks;

	two_stacks = *get_two_stacks();
	if (num == 3)
		return (ps_sort_three(two_stacks, stack_name));
	else if (num == 2)
		return (ps_sort_two(two_stacks, stack_name));
	else
	{
		if (stack_name == STACK_A)
			return (0);
		else if (stack_name == STACK_B)
			return (ps_print_operate(so_pa));
		return (0);
	}
}
