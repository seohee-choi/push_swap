/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:03:06 by jolim             #+#    #+#             */
/*   Updated: 2021/03/29 17:45:20 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OP_H
# define STACK_OP_H

# define SO_INT_MAX 2147483647
# define SO_INT_MIN -2147483648

# define CH_ERROR -1

# define DEBUG_FLAG 0x001
# define DEBUG_HOR_FLAG 0x002
# define COLOR_FLAG 0x004
# define FILE_FLAG 0x008
# define MAN_FLAG 0x010

# include <stdio.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct			s_ps_node
{
	struct s_ps_node	*up_node;
	int					element;
	struct s_ps_node	*down_node;
}						t_ps_node;

typedef struct			s_two_stacks
{
	t_ps_node			*a_top;
	t_ps_node			*b_top;
}						t_two_stacks;

/*
** functions of so_init_stacks.c initiate two_stacks or clear two_stacks.
*/

t_two_stacks			*so_init_stacks(int count, char **numbers);
void					clear_ps_stack(t_two_stacks *two_stacks);

/*
** functions of so_init_utils.c
**
** is_atoi returns true if str stands for an integer,
** and if it does, put the number into *n
*/

int						is_atoi(char *str, int *n);
void					*print_error(void);
void					*exit_error(void);

/*
** functions of so_node_utils.c manages nodes and lists
*/

t_ps_node				*new_ps_node(int element);
void					add_ps_node_bottom(t_ps_node **top, \
t_ps_node *new_node);
void					delete_ps_node_list(t_ps_node *node);
void					print_ps_node_list(t_ps_node *top);
void					print_ps_two_stacks(t_two_stacks *two_stacks, \
int option);

/*
** functions of so_operate_push.c / so_operate_rrotate.c / so_operate_rotate.c /
** so_operate_swap.c
*/
int						so_pa(void);
int						so_pb(void);
int						so_ra(void);
int						so_rb(void);
int						so_rr(void);
int						so_rra(void);
int						so_rrb(void);
int						so_rrr(void);
int						so_sa(void);
int						so_sb(void);
int						so_ss(void);
/*
** functions of so_push_pop_rotate.c do operations on only one stack.
*/

void					so_push_stack(t_ps_node **top, t_ps_node *new_node);
t_ps_node				*so_pop_stack(t_ps_node	**top);
void					so_rotate_stack(t_ps_node **top);
void					so_reverse_rotate_stack(t_ps_node **top);
void					so_swap_stack(t_ps_node **top);

/*
** functions of so_set_two_stacks.c
*/

t_two_stacks			**get_two_stacks(void);
void					set_two_stacks(t_two_stacks *two_stacks);

int						option_check(char **argv, int *option);

#endif
