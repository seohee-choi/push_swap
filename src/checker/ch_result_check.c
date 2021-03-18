/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_result_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:42:40 by jolim             #+#    #+#             */
/*   Updated: 2021/03/18 21:12:07 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_result(t_two_stacks *two_stacks)
{
	t_ps_node	*node;

	if (two_stacks->b_top != NULL)
	{
		ft_putendl_fd("KO", STDOUT_FILENO);
		return ;
	}
	node = two_stacks->a_top;
	while (node->down_node != two_stacks->a_top)
	{
		if (node->element > node->down_node->element)
		{
			ft_putendl_fd("KO", STDOUT_FILENO);
			return ;
		}
		node = node->down_node;
	}
	ft_putendl_fd("OK", STDOUT_FILENO);
	return ;
}