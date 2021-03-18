/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_push_pop_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:14:15 by jolim             #+#    #+#             */
/*   Updated: 2021/03/18 17:58:33 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

void	so_push_stack(t_ps_node **top, t_ps_node *new_node)
{
	t_ps_node	*bottom;
	t_ps_node	*prev_top;

	if (!*top)
	{
		*top = new_node;
		(*top)->up_node = *top;
		(*top)->down_node = *top;
	}
	bottom = (*top)->up_node;
	bottom->down_node = new_node;
	prev_top = *top;
	prev_top->up_node = new_node;
	*top = new_node;
	new_node->up_node = bottom;
	new_node->down_node = prev_top;
}

t_ps_node	*so_pop_stack(t_ps_node	**top)
{
	t_ps_node	*bottom;
	t_ps_node	*new_top;
	t_ps_node	*extractee;

	if (!*top)
		return(NULL);
	extractee = *top;
	if ((*top)->down_node == *top)
	{
		*top = NULL;
		return (extractee);
	}
	bottom = extractee->up_node;
	bottom->down_node = new_top;
	new_top = extractee->down_node;
	new_top->up_node = bottom;
	extractee->up_node = NULL;
	extractee->down_node = NULL;
	*top = new_top;
	return (extractee);
}

void	so_rotate_stack(t_ps_node **top)
{
	if (!*top)
		return ;
	*top = (*top)->down_node;
}

void	so_reverse_rotate_stack(t_ps_node **top)
{
	if (!*top)
		return ;
	*top = (*top)->up_node;
}

void	so_swap_stack(t_ps_node **top)
{
	t_ps_node	*bottom;
	t_ps_node	*top_node;
	t_ps_node	*sub_top;
	t_ps_node	*sub_sub_top;

	if (!*top || (*top)->down_node == *top)
		return ;
	bottom = (*top)->up_node;
	top_node = (*top)->down_node;
	sub_top = (*top);
	sub_sub_top = (*top)->down_node->down_node;
	bottom->down_node = top_node;
	top_node->up_node = bottom;
	top_node->down_node = sub_top;
	sub_top->up_node = *top;
	sub_top->down_node = sub_sub_top;
	sub_sub_top->up_node = sub_top;
}