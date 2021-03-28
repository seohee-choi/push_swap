/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:31:02 by jolim             #+#    #+#             */
/*   Updated: 2021/03/28 19:20:04 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <sys/stat.h>
#include <fcntl.h>

static int	input_from_file(char **argv)
{
	int	fd;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_strcmp("-f", argv[i]))
		{
			fd = open(argv[i + 1], O_RDONLY);
			if (fd == -1)
				return ((int)print_error() + CH_ERROR);
			dup2(fd, STDIN_FILENO);
			close(fd);
			return (0);
		}
		i++;
	}
	return ((int)print_error() + CH_ERROR);
}

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
	if (option & DEBUG_FLAG || option & DEBUG_HOR_FLAG)
		print_ps_two_stacks(*get_two_stacks(), option);
	free(line);
	if (ret == false)
		return ((int)print_error() + CH_ERROR);
	return (true);
}

void	print_operation_times(int times)
{
	ft_putstr_fd("operations: ", STDOUT_FILENO);
	ft_putnbr_fd(times, STDOUT_FILENO);
	ft_putendl_fd(" times", STDOUT_FILENO);
}

int	checker(int argc, char **argv, int option, int option_num)
{
	t_two_stacks	*two_stacks;
	int				times;
	int				ret;

	two_stacks = so_init_stacks(argc - option_num, &argv[option_num]);
	if (!two_stacks)
		return (-1);
	set_two_stacks(two_stacks);
	if (option & DEBUG_FLAG || option & DEBUG_HOR_FLAG)
		print_ps_two_stacks(two_stacks, option);
	ret = 1;
	times = -1;
	while (ret == 1)
	{
		ret = get_operation(option);
		times++;
	}
	if (option & DEBUG_FLAG)
		print_operation_times(times);
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

	if (argc == 1)
		return (0);
	option_num = option_check(argv, &option);
	if (option & MAN_FLAG)
		ch_print_manual();
	if (option & FILE_FLAG)
		if (input_from_file(argv) == CH_ERROR)
			return (-1);
	if (option_num == CH_ERROR || argc == option_num)
		return (-1);
	ret = checker(argc, argv, option, option_num);
	return (ret);
}
