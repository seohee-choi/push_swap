/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:28:18 by jolim             #+#    #+#             */
/*   Updated: 2021/03/16 21:24:30 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	p;

	p = 0;
	while (p < len)
	{
		*((unsigned char *)b + p) = (unsigned char)c;
		p++;
	}
	return (b);
}
