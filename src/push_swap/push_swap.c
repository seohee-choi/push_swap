/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:27:19 by jolim             #+#    #+#             */
/*   Updated: 2021/03/20 00:36:33 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(int list[], int argc)
{
	int i;
	char *str;

	i = 0;
	while(i < argc)
	{
		str = ft_itoa(list[i]);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		free(str);
		i++;
	}
}

int	push_swap(int argc, char **argv)
{
	t_two_stacks	*two_stacks;
	int				list[argc - 1];

	if (argc == 1)
		return (1);
	two_stacks = so_init_stacks(argc - 1, &argv[1]);
	if (!two_stacks)
		return (1);
	ps_init_list(list, two_stacks->a_top);
	quick_sort(list, 0, argc - 2);
	set_two_stacks(two_stacks);
	// if (argc == 4)
	// 	ps_sort_size_three();
	// else
		ps_sort_split_a(list, 0, argc - 2);
	clear_ps_stack(two_stacks);
	free(two_stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	if (push_swap(argc, argv))
		return (1);
	return (0);
}