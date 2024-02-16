/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:14:18 by mbico             #+#    #+#             */
/*   Updated: 2024/02/16 18:54:47 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	return (n & ~(1 << 31));
	
	// 0 & 0 = 0
	// 0 & 1 = 0
	// 1 & 0 = 0
	// 1 & 1 = 1
}
int	*rotate_cost(t_vars *v, int *best)
{
	int		i;
	int		actual;
	t_stack	*tmp;

	i = 0;
	tmp = v->s_b;
	while (tmp && i <= 2 * CHUNK)
	{
		actual = ft_stack_index(v->s_a, tmp->position);
		if (best[0] < ft_abs(actual) + i)
		{
			best[0] = ft_abs(actual) + i;
			best[1] = i;
		}
		tmp = tmp->next;
		i ++;
	}
	return (best);
}

void	revrotate_cost(t_vars *v, int *best)
{
	int		i;
	int		actual;
	t_stack	*tmp;

	i = 0;
	tmp = v->s_b;
	while (i >= -2 * CHUNK)
	{
		actual = ft_stack_index(v->s_a, tmp->position);
		if (best[0] < ft_abs(actual) - i)
		{
			best[0] = ft_abs(actual) - i;
			best[1] = i;
		}
		ft_stackrev_rotate(&tmp);
		i --;
	}
}

void	ft_insertion(t_vars *v, int i)
{
	while (i < 0)
	{
		revrotate(NULL, &v->s_b);
		i ++;
	}
	while (i > 0)
	{
		rotate(NULL, v->s_b);
		i --;
	}
	i = ft_stack_index(v->s_a, v->s_b->position);
	while (i < 0)
	{
		revrotate(&v->s_a, NULL);
		i ++;
	}
	while (i > 0)
	{
		rotate(v->s_a, NULL);
		i --;
	}
	push(&v->s_b, &v->s_a, 'a');
}

void	count_cost(t_vars *v)
{
	int		len;
	int		best[2];

	len = v->len;
	while (len >= 1)
	{
		best[0] = 2147483647;
		best[1] = 0;
		revrotate_cost(v, best);
		rotate_cost(v, best);
		ft_insertion(v, best[1]);
		len --;
	}
}