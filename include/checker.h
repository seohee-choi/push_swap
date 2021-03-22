/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:33:28 by jolim             #+#    #+#             */
/*   Updated: 2021/03/22 18:29:39 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define CH_NEWLINE 1
# define CH_EOF 0
# define CH_ERROR -1

# define DEBUG_FLAG 0b00000001
# define COLOR_FLAG 0b00000010
# define FILE_FLAG 0b00000100

# include "stack_op.h"

void	check_result(t_two_stacks *two_stacks);

int		checker(int argc, char **argv);
bool	do_operation(char *line);

#endif