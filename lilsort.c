/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lilsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:13:22 by mbico             #+#    #+#             */
/*   Updated: 2024/02/19 17:30:49 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_treesort(t_vars	*v)
{
	t_stack	*s;

	s = v->s_a;
	if (s->position == 1)
	{
		rotate(v->s_a);
		swap(v->s_a, NULL);
	}
}

void	ft_lilpresort(t_vars *v)
{
	t_stack	*tmp;
	t_stack	*ptr;

	tmp = v->s_a;
	ptr = v->s_a;
	while (ptr)
	{
		ptr->position += 1;
		while (tmp)
		{
			if (ptr->data > tmp->data)
				ptr->position ++;
			tmp = tmp->next;
		}
		tmp = v->s_a;
		ptr = ptr->next;
	}
	
}