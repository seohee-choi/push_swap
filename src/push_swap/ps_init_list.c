/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:09:01 by jolim             #+#    #+#             */
/*   Updated: 2021/03/18 18:29:004 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_init_list(int list[], t_ps_node *a_stack_top)
{
	t_ps_node	*node;
	int			i;

	node = a_stack_top;
	i = 0;
	while (node->down_node != a_stack_top)
	{
		list[i++] = node->element;
		node = node->down_node;
	}
	list[i] = node->element;
	return (list);
}