/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_register_operation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:42:36 by jolim             #+#    #+#             */
/*   Updated: 2021/03/29 17:42:33 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_registration(int **new_ps_register, int **old_ps_register)
{
	int	i;

	i = 0;
	while ((*old_ps_register)[i])
	{
		(*new_ps_register)[i] = (*old_ps_register)[i];
		i++;
	}
	return ;
}

static int	size_of_registrated(int *ps_register)
{
	int	size;

	if (!ps_register)
		return (0);
	size = 0;
	while (ps_register[size])
		size++;
	return (size);
}

static void	put_in_register(int op)
{
	static int	register_size = 0;
	int			size_registrated;
	int			**ps_register;
	int			*ps_new;

	ps_register = ps_get_register();
	size_registrated = size_of_registrated(*ps_register);
	if (size_registrated == BASE_SIZE * register_size)
	{
		ps_new = ft_calloc(BASE_SIZE * ++register_size + 1, sizeof(int));
		if (!ps_new)
		{
			print_error();
			exit(1);
		}
		copy_registration(&ps_new, ps_register);
		free(*ps_register);
		*ps_register = ps_new;
	}
	(*ps_register)[size_registrated] = op;
	return ;
}

int			ps_register_operation(int (*op)(void))
{
	if (op == so_pa)
		put_in_register(PA);
	else if (op == so_pb)
		put_in_register(PB);
	else if (op == so_sa)
		put_in_register(SA);
	else if (op == so_sb)
		put_in_register(SB);
	else if (op == so_ss)
		put_in_register(SS);
	else if (op == so_ra)
		put_in_register(RA);
	else if (op == so_rb)
		put_in_register(RB);
	else if (op == so_rr)
		put_in_register(RR);
	else if (op == so_rra)
		put_in_register(RRA);
	else if (op == so_rrb)
		put_in_register(RRB);
	else
		put_in_register(RRR);
	op();
	return (1);
}
