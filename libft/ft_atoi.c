/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:14:42 by jolim             #+#    #+#             */
/*   Updated: 2021/03/29 16:07:45 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\v')
		return (1);
	if (c == '\t' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int			p;
	long long	num;
	int			sign;

	if (*str == '\0')
		return (0);
	while (isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	p = 0;
	num = 0;
	while (*(str + p) <= '9' && *(str + p) >= '0')
	{
		num *= 10;
		num += (*(str + p) - '0') * sign;
		p++;
	}
	return (num);
}
