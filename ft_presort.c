/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:46:30 by mbico             #+#    #+#             */
/*   Updated: 2024/02/06 20:15:15 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insertion(t_stack *s, int i)
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
		ft_insertion(v->s_a, i);
		i ++;
	}
}
