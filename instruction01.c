/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:49:01 by mbico             #+#    #+#             */
/*   Updated: 2024/01/31 20:29:50 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s_a, t_stack *s_b)
{
	if (s_a && s_b)
	{
		ft_stackswap(s_a);
		ft_stackswap(s_b);
		write(1, "ss\n", 3);
	}
	else if (s_a)
	{
		ft_stackswap(s_a);
		write(1, "sa\n", 3);
	}
	else if (s_b)
	{
		ft_stackswap(s_b);
		write(1, "sb\n", 3);
	}
}

void	push(t_stack *s_a, t_stack *s_b)
{
	ft_stackpush(&s_b, &s_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *s_a, t_stack *s_b)
{
	ft_stackpush(&s_a, &s_b);
	write(1, "pb\n", 3);
}
