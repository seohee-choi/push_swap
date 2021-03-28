/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_register.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:50:04 by jolim             #+#    #+#             */
/*   Updated: 2021/03/28 16:19:32 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**ps_get_register(void)
{
	static int	*ps_register = NULL;

	if (ps_register == NULL)
		ps_register = ft_calloc(1, sizeof(int));
	return (&ps_register);
}

static int	printer(int *registration)
{
	static char	op_list[][4] = {" ", "pa", "pb", "sa", "sb", "ss", \
	"ra", "rb", "rr", "rra", "rrb", "rrr"};

	if ((*registration == SA && *(registration + 1) == SB) || \
		(*registration == SB && *(registration + 1) == SA))
	{
		ft_putendl_fd(op_list[SS], STDOUT_FILENO);
		return (2);
	}
	if ((*registration == RA && *(registration + 1) == RB) || \
		(*registration == RB && *(registration + 1) == RA))
	{
		ft_putendl_fd(op_list[RR], STDOUT_FILENO);
		return (2);
	}
	if ((*registration == RRA && *(registration + 1) == RRB) || \
		(*registration == RRB && *(registration + 1) == RRA))
	{
		ft_putendl_fd(op_list[RRR], STDOUT_FILENO);
		return (2);
	}
	ft_putendl_fd(op_list[*registration], STDOUT_FILENO);
	return (1);
}

void	ps_print_register(void)
{
	int	*ps_register;
	int	i;

	ps_register = *ps_get_register();
	i = 0;
	while (*ps_register)
		ps_register += printer(ps_register);
	ps_register = *ps_get_register();
	free(ps_register);
	return ;
}
