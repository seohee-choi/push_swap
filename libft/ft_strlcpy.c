/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 01:40:17 by jolim             #+#    #+#             */
/*   Updated: 2021/03/16 19:57:31 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	cpylen;
	size_t	p;

	if (dst == NULL || src == NULL)
		return (0);
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	if (dstsize < srclen + 1)
		cpylen = dstsize - 1;
	else
		cpylen = srclen;
	p = 0;
	while (p < cpylen)
	{
		*(dst + p) = *(src + p);
		p++;
	}
	*(dst + p) = '\0';
	return (srclen);
}
