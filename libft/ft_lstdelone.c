/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 13:55:43 by jolim             #+#    #+#             */
/*   Updated: 2021/03/11 23:43:03 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*garbage;

	if (!lst)
		return ;
	garbage = lst;
	lst = lst->next;
	if (garbage->content)
		del(garbage->content);
	free(garbage);
	garbage = NULL;
	return ;
}
