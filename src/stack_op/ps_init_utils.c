/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:50:24 by jolim             #+#    #+#             */
/*   Updated: 2021/03/17 23:42:11 by jolim            ###   ########.fr       */
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

bool	is_atoi(char *str, int *n)
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
	while (*str == '0')
		str++;
	num = 0;
	while (ft_isdigit(*str))
	{
		num = 10 * num + (*(str++) - '0') * sign;
		if (num > PS_INT_MAX || num < PS_INT_MIN)
			return (false);
	}
	if (!*str)
		return (true);
	*n = (int)num;
	return (true);
}

void	*print_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (NULL);
}

void	*malloc_failed(void)
{
	perror(NULL);
	return (NULL);
}
