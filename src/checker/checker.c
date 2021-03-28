/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:31:02 by jolim             #+#    #+#             */
/*   Updated: 2021/03/28 16:19:31 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	get_operation(void)
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
	if (ret == false)
		return ((int)print_error() + CH_ERROR);
	return (true);
}

static int	checker(int argc, char **argv)
{
	t_two_stacks	*two_stacks;
	int				ret;

	two_stacks = so_init_stacks(argc - 1, argv + 1);
	if (!two_stacks)
		return (-1);
	set_two_stacks(two_stacks);
	ret = 1;
	while (ret == 1)
		ret = get_operation();
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
