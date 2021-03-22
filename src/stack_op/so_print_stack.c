/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:02:11 by jolim             #+#    #+#             */
/*   Updated: 2021/03/22 18:01:29 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

static void	print_elements(t_ps_node **curr_a, t_ps_node **curr_b, \
bool *a_is_top, bool *b_is_top)
{
	t_two_stacks	*two_stacks;

	two_stacks = *get_two_stacks();
	ft_putstr_fd("\n", STDERR_FILENO);
	if (*a_is_top == false)
	{
		ft_putnbr_fd((*curr_a)->element, STDERR_FILENO);
		*curr_a = (*curr_a)->down_node;
	}
	if (*b_is_top == false)
	{
		write(1, "\t", 1);
		ft_putnbr_fd((*curr_b)->element, STDERR_FILENO);
		(*curr_b) = (*curr_b)->down_node;
	}
	if (*curr_a == two_stacks->a_top)
		*a_is_top = true;
	if (*curr_b == two_stacks->b_top)
		*b_is_top = true;
}

void	print_ps_two_stacks(t_two_stacks *two_stacks)
{
	t_ps_node	*curr_a;
	t_ps_node	*curr_b;
	bool		a_is_top;
	bool		b_is_top;

	if (!two_stacks)
		return ;
	a_is_top = false;
	b_is_top = false;
	curr_a = two_stacks->a_top;
	curr_b = two_stacks->b_top;
	if (!curr_a)
		a_is_top = true;
	if (!curr_b)
		b_is_top = true;
	ft_putstr_fd("----------", STDERR_FILENO);
	while (a_is_top == false || b_is_top == false)
		print_elements(&curr_a, &curr_b, &a_is_top, &b_is_top);
	ft_putstr_fd("\n----------\n", STDERR_FILENO);
	return ;
}
