/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:52:43 by jolim             #+#    #+#             */
/*   Updated: 2021/03/18 20:57:19 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack_op.h"

void	quick_sort(int number[], int first, int last);

/*
** a function of ps_init_lis.c
**
** ps_init_list reads numbers from the stack, 'a_stack_top'
** and allocates numbers to a new integer list.
*/

void	ps_init_list(int list[], t_ps_node *a_stack_top);

#endif