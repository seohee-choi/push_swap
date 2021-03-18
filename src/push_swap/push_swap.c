/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:27:19 by jolim             #+#    #+#             */
/*   Updated: 2021/03/18 18:47:09 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_two_stacks	*two_stacks;
	int				list[argc - 1];

	two_stacks = so_init_stacks(argc - 1, &argv[1]);
	if (!two_stacks)
		return (1);
	ps_init_list(list, two_stacks->a_top);
	quick_sort(list, 0, argc - 2);
	return (0);
}

int	main(int argc, char **argv)
{
	if (push_swap(argc, argv))
		return (1);
	return (0);
}