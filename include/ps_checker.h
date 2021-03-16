/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:33:28 by jolim             #+#    #+#             */
/*   Updated: 2021/03/16 18:53:21 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CHECKER_H
# define PS_CHECKER_H

typedef struct s_ps_node
{
	struct s_psnode	*up_node;
	int				element;
	struct s_psnode	*down_node;
}					t_ps_node;

typedef struct s_ps_stack
{
	t_ps_node	*a_top;
	t_ps_node	*b_top;
}					t_ps_stack;

#endif