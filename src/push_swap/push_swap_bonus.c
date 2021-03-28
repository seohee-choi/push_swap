/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:27:19 by jolim             #+#    #+#             */
/*   Updated: 2021/03/28 17:47:19 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <sys/stat.h>
#include <fcntl.h>

#include <err.h>

int		print_to_file(char **argv)
{
	int	fd;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_strcmp("-f", argv[i]))
		{
			fd = open(argv[i + 1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			if (fd == -1)
				return ((int)print_error() + CH_ERROR);
			dup2(fd, STDOUT_FILENO);
			close(fd);
			return (0);
		}
		i++;
	}
	return ((int)print_error() + CH_ERROR);
}

void	print_list(int list[], int argc)
{
	int		i;
	char	*str;

	i = 0;
	while (i < argc)
	{
		str = ft_itoa(list[i]);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		free(str);
		i++;
	}
}

int	push_swap(int argc, char **argv, int option, int option_num)
{
	t_two_stacks	*two_stacks;
	int				*list;

	two_stacks = so_init_stacks(argc - option_num, &argv[option_num]);
	if (!two_stacks)
		return (1);
	list = ft_calloc(argc - option_num + 1, sizeof(int));
	if (!list)
		return (-1);
	ps_init_list(list, two_stacks->a_top);
	quick_sort(list, 0, argc - option_num - 1);
	set_two_stacks(two_stacks);
	if (option & MAN_FLAG)
		ps_print_manual();
	if (argc - option_num == 3)
		ps_sort_size_three();
	else
		ps_sort_split_a_init(list, 0, argc - 1);
	ps_print_register();
	clear_ps_stack(two_stacks);
	free(list);
	free(two_stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	int	option;
	int	option_num;

	if (argc == 1)
		return (1);
	option = 0;
	option_num = option_check(argv, &option);
	set_option(option);
	if (option_num == CH_ERROR)
		return (-1);
	if (argc == option_num)
		return ((int)print_error() - 1);
	if (option & FILE_FLAG)
	{
		if (print_to_file(argv) == CH_ERROR)
			return (-1);
	}
	if (push_swap(argc, argv, option, option_num))
		return (1);
	return (0);
}
