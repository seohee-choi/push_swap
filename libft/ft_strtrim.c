/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:50:22 by jolim             #+#    #+#             */
/*   Updated: 2021/03/16 20:18:55 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	int	p;

	p = 0;
	while ((*(set + p)))
	{
		if (c == *(set + p))
			return (1);
		p++;
	}
	return (0);
}

static char	*return_zero(void)
{
	char	*new;

	new = malloc(sizeof(char));
	if (!new)
		return (NULL);
	*new = '\0';
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		head;
	int		tail;
	char	*new;
	int		newp;

	if (!s1)
		return (NULL);
	head = 0;
	tail = ft_strlen(s1) - 1;
	while (isset(*(s1 + head), set))
		head++;
	if (*(s1 + head) == '\0')
		return (return_zero());
	while (isset(*(s1 + tail), set))
		tail--;
	new = malloc((tail - head + 2) * sizeof(char));
	if (!new)
		return (NULL);
	newp = -1;
	while (head + ++newp < tail + 1)
		*(new + newp) = *(s1 + head + newp);
	*(new + newp) = '\0';
	return (new);
}
