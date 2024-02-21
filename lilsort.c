/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lilsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:13:22 by mbico             #+#    #+#             */
/*   Updated: 2024/02/21 17:50:12 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_treesort(t_vars	*v)
{
	if (!v->s_a || !v->s_a->next)
		return ;
	else if (!v->s_a->next->next && v->s_a->position > v->s_a->next->position)
		swap(v->s_a, NULL);
	else if (v->s_a->position > v->s_a->next->position && v->s_a->position > v->s_a->next->next->position)
	{
		rotate(v->s_a, NULL);
		if (v->s_a->position > v->s_a->next->position && v->s_a->position < v->s_a->next->next->position)
			swap(v->s_a, NULL);
	}
	else if (v->s_a->position < v->s_a->next->position && v->s_a->next->position > v->s_a->next->next->position)
	{
		revrotate(&v->s_a, NULL);
		if (v->s_a->position > v->s_a->next->position && v->s_a->position < v->s_a->next->next->position)
			swap(v->s_a, NULL);
	}
	else if (v->s_a->position > v->s_a->next->position && v->s_a->position < v->s_a->next->next->position)
			swap(v->s_a, NULL);
}

void	ft_fivesort(t_vars *v)
{
	int	len;

	len = v->len;
	while (len >= 1)
	{
		if (v->s_a->position <= 2)
			push(&v->s_a, &v->s_b, 'b');
		else
			rotate(v->s_a, NULL);
		len --;
	}
	ft_treesort(v);
	push(&v->s_b, &v->s_a, 'a');
	push(&v->s_b, &v->s_a, 'a');
	if (v->s_a->position > v->s_a->next->position)
		swap(v->s_a, NULL);
}