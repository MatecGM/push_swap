/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:46:30 by mbico             #+#    #+#             */
/*   Updated: 2024/02/24 14:22:01 by mbico            ###   ########.fr       */
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

int	ft_checkdouble(t_stack *s)
{
	t_stack	*actual;
	t_stack	*tmp;

	actual = s;
	while (actual)
	{
		tmp = actual->next;
		while (tmp)
		{
			if (actual->data == tmp->data)
				return (0);
			tmp = tmp->next;
		}
		actual = actual->next;
	}
	return (1);
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
