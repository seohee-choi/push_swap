/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:03:06 by jolim             #+#    #+#             */
/*   Updated: 2021/03/17 23:42:30 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_TWO_STACKS_H
# define PS_TWO_STACKS_H

# define PS_INT_MAX 2147483647
# define PS_INT_MIN -2147483648

# include <stdio.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_ps_node
{
	struct s_ps_node	*up_node;
	int					element;
	struct s_ps_node	*down_node;
}	t_ps_node;

typedef struct s_ps_stack
{
	t_ps_node	*a_top;
	t_ps_node	*b_top;
}	t_two_stacks;

t_two_stacks	*ps_init_stacks(int count, char **numbers);

/*
** functions of ps_node_utils.c manages nodes and lists
*/

t_ps_node	*new_ps_node(int element);
void	add_ps_node_bottom(t_ps_node **top, t_ps_node *new_node);
void	delete_ps_node_list(t_ps_node *node);
void	print_ps_node_list(t_ps_node *top);

/*
** functions of ps_init_utils.c
**
** is_atoi returns true if str stands for an integer,
** and if it does, put the number into *n
*/

bool	is_atoi(char *str, int *n);
void	*print_error(void);
void	*malloc_failed(void);

#endif
