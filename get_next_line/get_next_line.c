/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:50:07 by jolim             #+#    #+#             */
/*   Updated: 2021/03/16 20:30:47 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

int	get_next_line(int fd, char **line)
{
	static char	*backup = NULL;
	int			ret;

	if (line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (backup == NULL)
	{
		backup = (char *)malloc(1 * sizeof(char));
		if (!backup)
			return (-1);
		*backup = '\0';
	}
	ret = ft_reader(fd, &backup, line);
	return (ret);
}

int	ft_reader(int fd, char **backup, char **line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		len;
	int		rd_size;

	buffer[BUFFER_SIZE] = '\0';
	len = nl_finder(*backup);
	while (len < 0)
	{
		rd_size = read(fd, buffer, BUFFER_SIZE);
		if (rd_size <= 0)
			return (exception(rd_size, backup, line));
		else if (rd_size == 0 && **backup == 0)
			return (0);
		*backup = str_cat(*backup, buffer, rd_size);
		len = nl_finder(*backup);
	}
	if (put_line(*backup, line, len) == 0)
	{
		free(backup);
		return (-1);
	}
	*backup = str_cut(*backup, len);
	return (1);
}

int	exception(int rd_size, char **backup, char **line)
{
	int	i;

	if (rd_size == -1)
	{
		if (*backup != NULL)
			free(*backup);
		*backup = NULL;
		return (-1);
	}
	i = put_line(*backup, line, ft_strlen(*backup));
	if (i == 0)
	{
		if (*backup != NULL)
			free(*backup);
		*backup = NULL;
		return (-1);
	}
	if (*backup != NULL)
		free(*backup);
	*backup = NULL;
	return (0);
}
