/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:27:19 by jolim             #+#    #+#             */
/*   Updated: 2021/04/16 17:17:58 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sorted(t_two_stacks *two_stacks)
{
	t_ps_node	*node;

	node = two_stacks->a_top;
	while (node->down_node != two_stacks->a_top)
	{
		if (node->element > node->down_node->element)
			return (false);
		node = node->down_node;
	}
	return (true);
}

static int	push_swap(int argc, char **argv)
{
	t_two_stacks	*two_stacks;
	int				*list;

	two_stacks = so_init_stacks(argc - 1, argv + 1);
	if (!two_stacks)
		return (1);
	list = ft_calloc(argc - 1, sizeof(int));
	if (!list)
		return (-1);
	ps_init_list(list, two_stacks->a_top);
	if (check_sorted(two_stacks) == true)
	{
		clear_ps_stack(two_stacks);
		free(list);
		free(two_stacks);
		return (0);
	}
	quick_sort(list, 0, argc - 2);
	set_two_stacks(two_stacks);
	if (argc - 1 == 3)
		ps_sort_size_three();
	else
		ps_sort_split_a_init(list, 0, argc - 1);
	ps_print_register();
	clear_ps_stack(two_stacks);
	free(list);
	free(two_stacks);
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (push_swap(argc, argv))
		return (1);
	return (0);
}
