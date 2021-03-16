/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:39:12 by jolim             #+#    #+#             */
/*   Updated: 2021/03/16 20:19:14 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	p;

	if (!dst && !src)
		return (NULL);
	p = 0;
	while (p < n)
	{
		*((unsigned char *)dst + p) = *((unsigned char *)src + p);
		p++;
	}
	return (dst);
}
