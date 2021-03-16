/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:09:27 by jolim             #+#    #+#             */
/*   Updated: 2021/03/16 20:04:06 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	p;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		sub = (char *)malloc(1 * sizeof(char));
		if (!sub)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	p = 0;
	while (len > p && s[p] != '\0')
	{
		sub[p] = s[start + p];
		p++;
	}
	*(sub + p) = '\0';
	return (sub);
}
