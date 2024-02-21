/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:03:29 by mbico             #+#    #+#             */
/*   Updated: 2024/02/21 19:04:41 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_div_finder(t_stack *s_a, int pos)
{
	int	div;
	while (s_a)
	{
		if (s_a->position == pos)
			return (s_a->data);
		s_a = s_a->next;
	}
	return (s_a->data);
}

void	ft_init_divider(t_vars *v)
{
	int	i;

	v->div = ft_calloc(v->chunk * 2 + 1, sizeof(int));

	i = 1;
	v->div[0] = ft_div_finder(v->s_a, 1);
	while (i < v->chunk * 2)
	{
		v->div[i] = ft_div_finder(v->s_a, v->len / (v->chunk * 2) * i);
		i ++;
	}
	v->div[v->chunk * 2] = ft_div_finder(v->s_a, v->len);
}

void	ft_stock_on_b(t_vars *v)
{
	int	i;
	int	len;
	int	nb;

	i = 0;
	while (i <= v->chunk + 2)
	{
		len = ft_stacklen(v->s_a);
		while (len > 0)
		{
			nb = v->s_a->data;
			if ((nb >= v->div[i] && nb <= v->div[i + 1]))
			{
				push(&v->s_a, &v->s_b, 'b');
				rotate(NULL, v->s_b);
			}
			else if  (nb >= v->div[i + 1] && nb <= v->div[i + 2])
				push(&v->s_a, &v->s_b, 'b');
			else
				rotate(v->s_a, NULL);
			len --;
		}
		i += 2;
	}
}
