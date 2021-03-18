/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:19:23 by jolim             #+#    #+#             */
/*   Updated: 2021/03/18 21:16:2 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

t_ps_node	*new_ps_node(int element)
{
	t_ps_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_ps_node));
	if (!new_node)
		return (NULL);
	new_node->element = element;
	return (new_node);
}

void	add_ps_node_bottom(t_ps_node **top, t_ps_node *new_node)
{
	t_ps_node	*curr;

	if (!top)
		return ;
	if (!*top)
	{
		*top = new_node;
		new_node->up_node = new_node;
		new_node->down_node = new_node;
		return ;
	}
	curr = *top;
	while (curr->down_node != *top)
		curr = curr->down_node;
	curr->down_node = new_node;
	new_node->up_node = curr;
	new_node->down_node = *top;
	(*top)->up_node = new_node;
}

void	delete_ps_node_list(t_ps_node *node)
{
	t_ps_node	*curr;
	t_ps_node	*next;

	if (!node)
		return ;
	curr = node;
	if (curr->down_node && curr->down_node->up_node)
		curr->down_node->up_node = NULL;
	while (curr->up_node)
	{
		next = curr->up_node;
		free(curr);
		curr = NULL;
		curr = next;
	}
	free(curr);
	curr = NULL;
	return ;
}

void	print_ps_node_list(t_ps_node *top)
{
	t_ps_node	*curr;

	curr = top;
	if (!top)
		return ;
	while (curr->down_node != top)
	{
		ft_putnbr_fd(curr->element, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		curr = curr->down_node;
	}
	ft_putnbr_fd(curr->element, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return ;
}


void	print_ps_two_stacks(t_two_stacks *two_stacks)
{
	t_ps_node	*curr_a;
	t_ps_node	*curr_b;
	int a_is_top;
	int b_is_top;

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
	while (a_is_top == false || b_is_top == false)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		if (a_is_top == false)
		{
			ft_putnbr_fd(curr_a->element, STDOUT_FILENO);
			curr_a = curr_a->down_node;
		}
		if (b_is_top == false)
		{
			write(1, "\t", 1);
			ft_putnbr_fd(curr_b->element, STDOUT_FILENO);
			curr_b = curr_b->down_node;
		}
		if (curr_a && curr_a == two_stacks->a_top)
			a_is_top = true;
		if (curr_b && curr_b == two_stacks->b_top)
			b_is_top = true;
	}
	ft_putstr_fd("\n----------\n", STDOUT_FILENO);
	return ;
}
