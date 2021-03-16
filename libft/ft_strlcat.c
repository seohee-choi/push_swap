/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 01:56:43 by jolim             #+#    #+#             */
/*   Updated: 2021/03/16 20:12:49 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	int		p;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	p = 0;
	if (dstlen + 1 > dstsize)
		return (srclen + dstsize);
	while (p + dstlen + 1 < dstsize)
	{
		if (*(src + p) == '\0')
			break ;
		*(dst + dstlen + p) = *(src + p);
		p++;
	}
	*(dst + dstlen + p) = '\0';
	return (dstlen + srclen);
}
