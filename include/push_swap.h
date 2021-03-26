/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:52:43 by jolim             #+#    #+#             */
/*   Updated: 2021/03/26 21:54:54 by jolim            ###   ########.fr       */
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

# define BASE_SIZE 5000

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
** ps_print_register prints the registered operations and merge them if it can
*/

int		**ps_get_register(void);
void	ps_print_register(void);

/*
** a function of ps_register_operation.c
**
** ps_register_operation receives one of stack_op operations, then saves it to
** ps_register.
*/

int		ps_register_operation(bool (*op)(void));

/*
** functions of ps_simulator.c
*/

void	ps_sort_split_a_init(int list[], int top, int bottom);
void	ps_sort_split_a(int list[], int top, int bottom);
void	ps_sort_split_b(int list[], int top, int bottom);

/*
** functions of ps_simulator_utils.c does simple calculations for push_swap
** simulator.
*/

int		pivot_big(int top, int bottom);
int		pivot_small(int top, int bottom);
int		max_num(int a, int b);
int		min_num(int a, int b);
void	ps_operate_n_times(int n, bool (*op)(void));

/*
** ps_simulator_few.c, ps_size_three.c, ps_size_five.c
*/

int		ps_sort_below_three(int num, int stack_name);
int		ps_sort_size_three(void);
int		ps_sort_size_five(int list[]);

/*
** ps_option.c
*/

void	set_option(int option);
int		*get_option(void);
void	ps_print_manual(void);

#endif
