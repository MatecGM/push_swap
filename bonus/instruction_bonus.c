/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:29:57 by mbico             #+#    #+#             */
/*   Updated: 2024/02/29 20:57:56 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_double_instr(t_vars *v, char *s, int len)
{
	if (!ft_strncmp(s, "rrr\n", len))
	{
		ft_stackrev_rotate(&v->s_a);
		ft_stackrev_rotate(&v->s_b);
	}
	else if (!ft_strncmp(s, "rr\n", len))
	{
		ft_stackrotate(v->s_a);
		ft_stackrotate(v->s_b);
	}
	else
		return (1);
	return (0);
}

int	ft_intruction_read(t_vars *v, char *s)
{
	int	len;

	len = ft_strlen(s);
	if (!ft_strncmp(s, "sa\n", len))
		ft_stackswap(v->s_a);
	else if (!ft_strncmp(s, "sb\n", len))
		ft_stackswap(v->s_b);
	else if (!ft_strncmp(s, "ra\n", len))
		ft_stackrotate(v->s_a);
	else if (!ft_strncmp(s, "rb\n", len))
		ft_stackrotate(v->s_b);
	else if (!ft_strncmp(s, "rra\n", len))
		ft_stackrev_rotate(&v->s_a);
	else if (!ft_strncmp(s, "rrb\n", len))
		ft_stackrev_rotate(&v->s_b);
	else if (!ft_strncmp(s, "pa\n", len))
		ft_stackpush(&v->s_b, &v->s_a);
	else if (!ft_strncmp(s, "pb\n", len))
		ft_stackpush(&v->s_a, &v->s_b);
	else
	{
		if (ft_double_instr(v, s, len))
			return (1);
	}
	return (0);
}
