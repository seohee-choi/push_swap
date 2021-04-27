/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_do_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:02:38 by jolim             #+#    #+#             */
/*   Updated: 2021/03/29 17:41:49 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	do_operation(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		return (so_sa());
	else if (ft_strcmp(line, "sb") == 0)
		return (so_sb());
	else if (ft_strcmp(line, "ss") == 0)
		return (so_ss());
	else if (ft_strcmp(line, "pa") == 0)
		return (so_pa());
	else if (ft_strcmp(line, "pb") == 0)
		return (so_pb());
	else if (ft_strcmp(line, "ra") == 0)
		return (so_ra());
	else if (ft_strcmp(line, "rb") == 0)
		return (so_rb());
	else if (ft_strcmp(line, "rr") == 0)
		return (so_rr());
	else if (ft_strcmp(line, "rra") == 0)
		return (so_rra());
	else if (ft_strcmp(line, "rrb") == 0)
		return (so_rrb());
	else if (ft_strcmp(line, "rrr") == 0)
		return (so_rrr());
	return (false);
}
