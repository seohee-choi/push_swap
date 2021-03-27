/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:47:36 by jolim             #+#    #+#             */
/*   Updated: 2021/03/27 19:10:42 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

static bool	is_duplicated(t_ps_node *top, int n)
{
	t_ps_node	*curr;

	if (!top)
		return (false);
	curr = top;
	while (curr->down_node != top)
	{
		if (curr->element == n)
			return (true);
		curr = curr->down_node;
	}
	if (curr->element == n)
		return (true);
	return (false);
}

static t_two_stacks	*add_str_a_stack(t_two_stacks *two_stacks, char *num)
{
	t_ps_node	*new_node;
	int			n;

	if (!is_atoi(num, &n))
	{
		clear_ps_stack(two_stacks);
		return (print_error());
	}
	if (is_duplicated(two_stacks->a_top, n))
	{
		clear_ps_stack(two_stacks);
		return (print_error());
	}
	new_node = new_ps_node(n);
	if (!new_node)
	{
		clear_ps_stack(two_stacks);
		return (exit_error());
	}
	add_ps_node_bottom(&(two_stacks->a_top), new_node);
	return (two_stacks);
}

t_two_stacks	*so_init_stacks(int count, char **numbers)
{
	t_two_stacks	*two_stacks;
	int				i;

	two_stacks = ft_calloc(1, sizeof(t_two_stacks));
	i = 0;
	while (i < count)
	{
		two_stacks = add_str_a_stack(two_stacks, numbers[i]);
		if (!two_stacks)
		{
			free(two_stacks);
			two_stacks = NULL;
			return (NULL);
		}
		i++;
	}
	return (two_stacks);
}

void	clear_ps_stack(t_two_stacks *two_stacks)
{
	delete_ps_node_list(two_stacks->a_top);
	delete_ps_node_list(two_stacks->b_top);
	return ;
}
