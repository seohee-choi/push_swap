/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:19:23 by jolim             #+#    #+#             */
/*   Updated: 2021/03/17 23:42:07 by jolim            ###   ########.fr       */
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
	{
		curr = curr->down_node;
	}
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
		curr = next;
	}
	curr = node;
	if (curr->up_node && curr->up_node->down_node)
		curr->up_node->down_node = NULL;
	while (curr->down_node)
	{
		next = curr->down_node;
		free(curr);
		curr = next;
	}
	return ;
}

void	print_ps_node_list(t_ps_node *top)
{
	t_ps_node	*curr;

	curr = top;
	while (curr->down_node != top)
	{
		ft_putnbr_fd(curr->element, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		curr = curr->down_node;
	}
	return ;
}
