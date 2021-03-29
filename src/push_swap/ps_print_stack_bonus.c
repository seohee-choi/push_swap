/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_stack_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:02:11 by jolim             #+#    #+#             */
/*   Updated: 2021/03/29 17:42:17 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

static void	print_elements(t_ps_node **curr_a, t_ps_node **curr_b, \
int *a_is_top, int *b_is_top)
{
	t_two_stacks	*two_stacks;

	system("clear");
	two_stacks = *get_two_stacks();
	ft_putstr_fd("\nA\tB", STDOUT_FILENO);
	while (*a_is_top == false || *b_is_top == false)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		if (*a_is_top == false)
		{
			ft_putnbr_fd((*curr_a)->element, STDOUT_FILENO);
			*curr_a = (*curr_a)->down_node;
		}
		if (*b_is_top == false)
		{
			write(1, "\t", 1);
			ft_putnbr_fd((*curr_b)->element, STDOUT_FILENO);
			(*curr_b) = (*curr_b)->down_node;
		}
		if (*curr_a == two_stacks->a_top)
			*a_is_top = true;
		if (*curr_b == two_stacks->b_top)
			*b_is_top = true;
	}
	usleep(10000);
}

static void	print_elements_horizontal(t_ps_node **curr_a, \
t_ps_node **curr_b, int *a_is_top, int *b_is_top)
{
	t_two_stacks	*two_stacks;

	system("clear");
	two_stacks = *get_two_stacks();
	ft_putstr_fd("\n A : ", STDOUT_FILENO);
	while (*a_is_top == false)
	{
		ft_putnbr_fd((*curr_a)->element, STDOUT_FILENO);
		ft_putstr_fd(" ", STDOUT_FILENO);
		*curr_a = (*curr_a)->down_node;
		if (*curr_a == two_stacks->a_top)
			*a_is_top = true;
	}
	ft_putstr_fd("\n\n B : ", STDOUT_FILENO);
	while (*b_is_top == false)
	{
		ft_putnbr_fd((*curr_b)->element, STDOUT_FILENO);
		ft_putstr_fd(" ", STDOUT_FILENO);
		(*curr_b) = (*curr_b)->down_node;
		if (*curr_b == two_stacks->b_top)
			*b_is_top = true;
	}
	usleep(10000);
}

void		print_ps_two_stacks(t_two_stacks *two_stacks, int option)
{
	t_ps_node	*curr_a;
	t_ps_node	*curr_b;
	int			a_is_top;
	int			b_is_top;

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
	ft_putstr_fd("----------", STDOUT_FILENO);
	if (option & DEBUG_HOR_FLAG)
		print_elements_horizontal(&curr_a, &curr_b, &a_is_top, &b_is_top);
	else
		print_elements(&curr_a, &curr_b, &a_is_top, &b_is_top);
	ft_putstr_fd("\n----------\n", STDOUT_FILENO);
	return ;
}
