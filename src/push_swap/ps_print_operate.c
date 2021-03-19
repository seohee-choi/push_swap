/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_operate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:42:36 by jolim             #+#    #+#             */
/*   Updated: 2021/03/19 16:57:01 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_print_operate(bool (*op)(void))
{
	if (op == so_pa)
		ft_putendl_fd("pa", STDOUT_FILENO);
	else if (op == so_pb)
		ft_putendl_fd("pb", STDOUT_FILENO);
	else if (op == so_sa)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (op == so_sb)
		ft_putendl_fd("sb", STDOUT_FILENO);
	else if (op == so_ss)
		ft_putendl_fd("ss", STDOUT_FILENO);
	else if (op == so_ra)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (op == so_rb)
		ft_putendl_fd("rb", STDOUT_FILENO);
	else if (op == so_rr)
		ft_putendl_fd("rr", STDOUT_FILENO);
	else if (op == so_rra)
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (op == so_rrb)
		ft_putendl_fd("rrb", STDOUT_FILENO);
	else if (op == so_rrr)
		ft_putendl_fd("rrr", STDOUT_FILENO);
	op();
	return (1);
}
