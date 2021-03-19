/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:31:02 by jolim             #+#    #+#             */
/*   Updated: 2021/03/20 00:10:33 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	get_operation(t_two_stacks *two_stacks)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = get_next_line(STDIN_FILENO, &line);
	if (ret == CH_ERROR)
	{
		print_error();
		return (CH_ERROR);
	}
	if (ret == CH_EOF)
	{
		if (line)
			free(line);
		return (CH_EOF);
	}
	ret = do_operation(line);
	free(line);
	print_ps_two_stacks(two_stacks);
	if (ret == false)
	{
		print_error();
		return (CH_ERROR);
	}
	return (true);
}

int	checker(int argc, char **argv)
{
	t_two_stacks	*two_stacks;
	int				times;
	int				ret;

	two_stacks = so_init_stacks(argc - 1, &argv[1]);
	if (!two_stacks)
		return (-1);
	print_ps_node_list(two_stacks->a_top);
	set_two_stacks(two_stacks);
	ret = 1;
	times = -1;
	while (ret == 1)
	{
		ret = get_operation(two_stacks);
		times++;
	}
	ft_putstr_fd("operations: ", STDOUT_FILENO);
	ft_putnbr_fd(times, STDOUT_FILENO);
	ft_putendl_fd(" times", STDOUT_FILENO);
	if (ret == 0)
		check_result(two_stacks);
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
	return (ret);
}