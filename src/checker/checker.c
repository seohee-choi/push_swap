/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:31:02 by jolim             #+#    #+#             */
/*   Updated: 2021/03/22 20:12:23 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	get_operation(int option)
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
	if (option & DEBUG_FLAG)
		print_ps_two_stacks(*get_two_stacks());
	free(line);
	if (ret == false)
	{
		print_error();
		return (CH_ERROR);
	}
	return (true);
}

int	checker(int argc, char **argv, int option, int option_num)
{
	t_two_stacks	*two_stacks;
	int				times;
	int				ret;

	two_stacks = so_init_stacks(argc - option_num, &argv[option_num]);
	if (!two_stacks || option == CH_ERROR)
		return (-1);
	set_two_stacks(two_stacks);
	if (option & DEBUG_FLAG)
		print_ps_two_stacks(two_stacks);
	ret = 1;
	times = -1;
	while (ret == 1)
	{
		ret = get_operation(option);
		times++;
	}
	if (option & DEBUG_FLAG)
	{
		ft_putstr_fd("operations: ", STDOUT_FILENO);
		ft_putnbr_fd(times, STDOUT_FILENO);
		ft_putendl_fd(" times", STDOUT_FILENO);
	}
	if (ret == 0)
		check_result(two_stacks);
	clear_ps_stack(two_stacks);
	free(two_stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	int	ret;
	int	option;
	int option_num;

	// option = 0;
	// option_num = 1;
	if (argc == 1)
		return (0);
	// if (argv[1][0] == '-')
		option_num = option_check(argv, &option);
	ret = checker(argc, argv, option, option_num);
	return (ret);
}
