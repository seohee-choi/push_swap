/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:33:28 by jolim             #+#    #+#             */
/*   Updated: 2021/03/26 15:33:52 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define CH_NEWLINE 1
# define CH_EOF 0
# define CH_ERROR -1

# include "stack_op.h"

void	check_result(t_two_stacks *two_stacks);
bool	do_operation(char *line);
void	ch_print_manual(void);

#endif
