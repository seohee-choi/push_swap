/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:33:28 by jolim             #+#    #+#             */
/*   Updated: 2021/03/18 21:11:44 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CHECKER_H
# define PS_CHECKER_H

# define CH_NEWLINE 1
# define CH_EOF 0
# define CH_ERROR -1

# include "stack_op.h"

void	check_result(t_two_stacks *two_stacks);

int	checker(int argc, char **argv);
bool do_operation(char *line);

#endif