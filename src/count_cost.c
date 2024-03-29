/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:14:18 by mbico             #+#    #+#             */
/*   Updated: 2024/02/24 11:23:08 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	ft_last_rotate(t_vars *v)
{
	if (v->s_a->position > v->len / 2)
	{
		while (v->s_a->position != 1)
			rotate(v->s_a, NULL);
	}
	else
	{
		while (v->s_a->position != 1)
			revrotate(&v->s_a, NULL);
	}
}

int	*rotate_cost(t_vars *v, int *best, int len)
{
	int		i;
	int		j;
	int		actual;
	t_stack	*tmp;

	i = 0;
	tmp = v->s_b;
	while (tmp && i < len)
	{
		actual = ft_stack_index(v->s_a, tmp->position);
		j = i;
		if (i > len / 2)
			j = i - len;
		if (best[0] > ft_abs(actual) + ft_abs(j))
		{
			best[0] = ft_abs(actual) + ft_abs(j);
			best[1] = j;
			v->rot_a = actual;
		}
		tmp = tmp->next;
		i ++;
	}
	return (best);
}

void	doublerotation(t_vars *v)
{
	while (v->rot_a < 0 && v->rot_b < 0)
	{
		revrotate(&v->s_a, &v->s_b);
		v->rot_a ++;
		v->rot_b ++;
	}
	while (v->rot_a > 0 && v->rot_b > 0)
	{
		rotate(v->s_a, v->s_b);
		v->rot_a --;
		v->rot_b --;
	}
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
		rotate_cost(v, best, len);
		v->rot_b = best[1];
		doublerotation(v);
		ft_insertion(v);
		len --;
	}
}
