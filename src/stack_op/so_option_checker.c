/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_option_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:37:01 by seohchoi          #+#    #+#             */
/*   Updated: 2021/03/25 02:56:26 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

int	option_check(char **argv, int *option)
{
	int i;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (ft_strcmp("-v", argv[i]) && ft_strcmp("-c", argv[i]) && \
		ft_strcmp("-f", argv[i]) && ft_strcmp("-m", argv[i]) && \
		ft_strcmp("-vw", argv[i]))
			return ((int)print_error() + CH_ERROR);
		else if (ft_strcmp("-v", argv[i]) == 0)
			*option |= DEBUG_FLAG;
		else if (ft_strcmp("-vw", argv[i]) == 0)
			*option |= DEBUG_HOR_FLAG;
		else if (ft_strcmp("-c", argv[i]) == 0)
			*option |= COLOR_FLAG;
		else if (ft_strcmp("-f", argv[i]) == 0)
			*option |= FILE_FLAG;
		else if (ft_strcmp("-m", argv[i]) == 0)
			*option |= MAN_FLAG;
		if (*option & DEBUG_FLAG && *option & DEBUG_HOR_FLAG)
			return ((int)print_error() + CH_ERROR);
		i++;
	}
	return (i);
}
