/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:40:46 by jolim             #+#    #+#             */
/*   Updated: 2021/03/16 19:58:30 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	iterater(t_list *lst, void (*f)(void *))
{
	if (lst->content != NULL)
		f(lst->content);
	if (lst->next != NULL)
		iterater(lst->next, f);
	return ;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	iterater(lst, f);
	return ;
}
