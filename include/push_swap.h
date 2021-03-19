/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:52:43 by jolim             #+#    #+#             */
/*   Updated: 2021/03/19 22:57:25 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STACK_A 1
# define STACK_B 2

# define TOP 0
# define MID 1
# define BTM 2

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
** a function of ps_print_operate.c
**
** ps_print_operate receives one of stack_op operations, then print and operate
** the operation.
*/

int	ps_print_operate(bool (*op)(void));

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