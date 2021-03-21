/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:52:43 by jolim             #+#    #+#             */
/*   Updated: 2021/03/21 17:35:43 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STACK_A (1)
# define STACK_B (2)

# define TOP (0)
# define MID (1)
# define BTM (2)

# define PA (1)
# define PB (2)
# define SA (3)
# define SB (4)
# define SS (5)
# define RA (6)
# define RB (7)
# define RR (8)
# define RRA (9)
# define RRB (10)
# define RRR (11)

# define RG_BASE_SIZE 5000

# include "stack_op.h"

void	quick_sort(int number[], int first, int last);

/*
** a function of ps_init_lis.c
**
** ps_init_list reads numbers from the stack, 'a_stack_top'
** and allocates numbers to a new integer list.
*/

void	ps_init_list(int list[], t_ps_node *a_stack_top);

/*
** functions of ps_print_register.c
**
** ps_get_register returns a pointer to ps_register, which will save operations
** from the function ps_register_operation.
**
** ps_get_op_list returns a pointer to char const * const *op_list, which
** contains literal strings of the 11 operations.
*/

int	**ps_get_register(void);
char const * const	**ps_get_op_list(void);

/*
** a function of ps_register_operation.c
**
** ps_register_operation receives one of stack_op operations, then saves it to
** ps_register.
*/

int	ps_register_operation(bool (*op)(void));

/*
** functions of ps_simulator.c
*/

void	ps_sort_split_a(int list[], int top, int bottom);
void	ps_sort_split_b(int list[], int top, int bottom);

/*
** functions of ps_simulator_utils.c does simple calculations for push_swap
** simulator.
*/

int	pivot_big(int top, int bottom);
int	pivot_small(int top, int bottom);
int	max_num(int a, int b);
int	min_num(int a, int b);
void	ps_operate_n_times(int n, bool (*op)(void));

/*
** ps_simulator_few.c, ps_size_three.c
*/

int	ps_sort_below_three(int num, int stack_name);
int	ps_sort_size_three(void);

#endif