/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:46:30 by mbico             #+#    #+#             */
/*   Updated: 2024/02/21 15:51:54 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	i = 1;
	while (i <= v->len)
	{
		ft_indexer(v->s_a, i);
		i ++;
	}
}
