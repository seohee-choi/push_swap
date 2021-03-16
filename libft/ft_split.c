/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:11:52 by yongwkim          #+#    #+#             */
/*   Updated: 2021/03/16 20:02:57 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sizeof_ret(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s && *s != c)
				s++;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int	get_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	**free_arr(char **ret, int cnt)
{
	while (cnt-- >= 0)
		free((void *)ret[cnt]);
	free(ret);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char		**ret;
	int			cnt;
	int			len_word;

	if (!s)
		return (0);
	ret = (char **)malloc((get_sizeof_ret(s, c) + 1) * sizeof(char *));
	if (!ret)
		return (0);
	cnt = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		len_word = get_word_len(s, c);
		ret[cnt] = (char *)malloc((len_word + 1) * sizeof(char));
		if (!ret[cnt])
			return (free_arr(ret, cnt));
		ft_strlcpy(ret[cnt++], s, len_word + 1);
		s += len_word;
	}
	ret[cnt] = 0;
	return (ret);
}
