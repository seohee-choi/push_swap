/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:46:34 by jolim             #+#    #+#             */
/*   Updated: 2021/02/24 18:31:14 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	p;

	p = 0;
	while ((*(s1 + p) == *(s2 + p)))
	{
		if (*(s1 + p) == '\0')
			return (0);
		p++;
	}
	return (*(unsigned char *)(s1 + p) - *(unsigned char *)(s2 + p));
}
