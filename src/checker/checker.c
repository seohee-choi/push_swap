/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:31:02 by jolim             #+#    #+#             */
/*   Updated: 2021/03/17 23:58:38 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int checker(int argc, char **argv)
{
	t_two_stacks	*two_stacks;

	two_stacks = ps_init_stacks(argc - 1, &argv[1]);
	if (!two_stacks)
		return (1);
	print_ps_node_list(two_stacks->a_top);
	return (0);
}

int	main(int argc, char **argv)
{
	int	ret;

	if (argc == 1)
		return (0);
	ret = checker(argc, argv);
	return (ret);
}