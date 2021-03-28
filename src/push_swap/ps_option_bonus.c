/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_option_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:39:05 by seohchoi          #+#    #+#             */
/*   Updated: 2021/03/28 16:52:52 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <sys/stat.h>
#include <fcntl.h>

int	*get_option(void)
{
	static int option = 0;

	return (&option);
}

void	set_option(int option)
{
	int	*option_setting;

	option_setting = get_option();
	*option_setting = option;
}

void	ps_print_manual(void)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	int		rd_size;

	fd = open("push_swap_man.txt", O_RDONLY);
	if (fd < 0)
		return ;
	rd_size = 1;
	while (rd_size > 0)
	{
		rd_size = read(fd, buffer, BUFFER_SIZE);
		if (rd_size == -1)
			return;
		write(STDOUT_FILENO, buffer, rd_size);
	}
	write(STDOUT_FILENO, "\n", 1);
	return ;
}
