/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:03:06 by jolim             #+#    #+#             */
/*   Updated: 2021/03/18 18:28:34 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OP_H
# define STACK_OP_H

# define SO_INT_MAX (2147483647)
# define SO_INT_MIN (-2147483648)

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

typedef struct s_two_stacks
{
	t_ps_node	*a_top;
	t_ps_node	*b_top;
}	t_two_stacks;


/*
** functions of so_init_stacks.c initiate two_stacks or clear two_stacks.
*/

t_two_stacks	*so_init_stacks(int count, char **numbers);
void	clear_ps_stack(t_two_stacks *two_stacks);

/*
** functions of so_init_utils.c
**
** is_atoi returns true if str stands for an integer,
** and if it does, put the number into *n
*/

bool	is_atoi(char *str, int *n);
void	*print_error(void);
void	*exit_error(void);

/*
** functions of so_node_utils.c manages nodes and lists
*/

t_ps_node	*new_ps_node(int element);
void	add_ps_node_bottom(t_ps_node **top, t_ps_node *new_node);
void	delete_ps_node_list(t_ps_node *node);
void	print_ps_node_list(t_ps_node *top);

/*
** functions of so_operate_push.c / so_operate_rrotate.c / so_operate_rotate.c /
** so_operate_swap.c
*/
bool	so_pa(void);
bool	so_pb(void);
bool	so_ra(void);
bool	so_rb(void);
bool	so_rr(void);
bool	so_rra(void);
bool	so_rrb(void);
bool	so_rrr(void);
bool	so_sa(void);
bool	so_sb(void);
bool	so_ss(void);
/*
** functions of so_push_pop_rotate.c do operations on only one stack.
*/

void	so_push_stack(t_ps_node **top, t_ps_node *new_node);
t_ps_node	*so_pop_stack(t_ps_node	**top);
void	so_rotate_stack(t_ps_node **top);
void	so_reverse_rotate_stack(t_ps_node **top);
void	so_swap_stack(t_ps_node **top);

/*
** functions of so_set_two_stacks.c
*/

t_two_stacks	**get_two_stacks(void);
void	set_two_stacks(t_two_stacks *two_stacks);

#endif
