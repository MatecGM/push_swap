/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:46:30 by mbico             #+#    #+#             */
/*   Updated: 2024/02/29 21:11:28 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_indexer(t_stack *s, int i)
{
	t_stack	*min;
	int		nb;

	nb = 2147483647;
	while (s)
	{
		if (nb >= s->data && s->position == 0)
		{
			min = s;
			nb = s->data;
		}
		s = s->next;
	}
	min->position = i;
}

void	ft_presort(t_vars *v)
{
	int		i;
	int		len;

	i = 1;
	len = ft_stacklen(v->s_a);
	while (i <= len)
	{
		ft_indexer(v->s_a, i);
		i ++;
	}
}
