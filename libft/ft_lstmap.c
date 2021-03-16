/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:47:57 by jolim             #+#    #+#             */
/*   Updated: 2021/03/16 20:02:43 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*copy_node(\
		t_list *target, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;

	new_node = ft_lstnew(f(target->content));
	if (!new_node)
		return (NULL);
	if (target->next != NULL)
	{
		new_node->next = copy_node(target->next, f, del);
		if (!new_node->next)
		{
			del(new_node->content);
			free(new_node);
			return (NULL);
		}
		return (new_node);
	}
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;

	if (lst == NULL)
		return (NULL);
	copy = copy_node(lst, f, del);
	if (!copy)
		return (NULL);
	return (copy);
}
