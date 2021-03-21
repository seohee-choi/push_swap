/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_register.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:50:04 by jolim             #+#    #+#             */
/*   Updated: 2021/03/21 17:41:39 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**ps_get_register(void)
{
	static int	*ps_register = NULL;

	return (&ps_register);
}

char const * const	**ps_get_op_list(void)
{
	static char const * const	op_list[] = {"", "pa", "pb", "sa", "sb", "ss", "ra", "rb", "rr",\
	"rra", "rrb", "rrr"};

	return (&op_list);
}