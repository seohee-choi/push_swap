/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:50:24 by jolim             #+#    #+#             */
/*   Updated: 2021/03/29 17:46:51 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\v' || \
	c == '\t' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

int			is_atoi(char *str, int *n)
{
	long long	num;
	int			sign;

	while (is_space(*str))
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (false);
	while (*str == '0')
		str++;
	num = 0;
	while (ft_isdigit(*str))
	{
		num = 10 * num + (*(str++) - '0') * sign;
		if (num > SO_INT_MAX || num < SO_INT_MIN)
			return (false);
	}
	*n = (int)num;
	if (!*str)
		return (true);
	return (false);
}

void		*print_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (NULL);
}

void		*exit_error(void)
{
	exit(1);
	return (NULL);
}
