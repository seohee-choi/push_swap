/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:31:02 by jolim             #+#    #+#             */
/*   Updated: 2021/03/18 18:48:23 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checker(int argc, char **argv)
{
	t_two_stacks	*two_stacks;
	char			*line;
	int				ret;

	two_stacks = so_init_stacks(argc - 1, &argv[1]);
	if (!two_stacks)
		return (1);
	print_ps_node_list(two_stacks->a_top);
	set_two_stacks(two_stacks);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret == -1)
			break;
		if (!do_operation(line))
			break;
	}
	clear_ps_stack(two_stacks);
	free(two_stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	int	ret;

	if (argc == 1)
		return (0);
	ret = checker(argc, argv);
	// system("leaks checker");
	return (ret);
}