/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:06:29 by mbico             #+#    #+#             */
/*   Updated: 2024/02/13 17:35:38 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_index(t_stack	*s, int pos)
{
	int	i;

	i = 0;
	while (s && s->position != pos)
	{
		s = s->next;
		i ++;
	}
	return (i);
}

void	ft_selection(t_vars *v)
{
	while (v->len >= 1)
	{
		if (ft_stack_index(v->s_b, v->len) <= v->len / 2)
		{
			while (v->s_b->position != v->len && v->s_b->next)
				rotate(NULL, v->s_b);
		}
		else
		{
			while (v->s_b->position != v->len && v->s_b->next)
			{
				revrotate(NULL, &v->s_b);
			}
		}
		push(&v->s_b, &v->s_a, 'a');
		v->len --;
	}
}
