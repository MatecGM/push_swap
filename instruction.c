/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:49:01 by mbico             #+#    #+#             */
/*   Updated: 2024/02/01 16:23:52 by mbico            ###   ########.fr       */
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

void	push(t_stack *s_1, t_stack *s_2, char letter)
{
	ft_stackpush(&s_1, &s_2);
	if (letter == 'a')
		write(1, "pa\n", 3);
	else if (letter == 'b')
		write(1, "pb\n", 3);
}

void	rotate(t_stack *s_a, t_stack *s_b)
{
	if (s_a && s_b)
	{
		ft_stackrotate(s_a);
		ft_stackrotate(s_b);
		write(1, "rr\n", 3);
	}
	else if (s_a)
	{
		ft_stackrotate(s_a);
		write(1, "ra\n", 3);
	}
	else if (s_b)
	{
		ft_stackrotate(s_b);
		write(1, "rb\n", 3);
	}
}

void	revrotate(t_stack *s_a, t_stack *s_b)
{
	if (s_a && s_b)
	{
		ft_stackrev_rotate(&s_a);
		ft_stackrev_rotate(&s_b);
		write(1, "rrr\n", 4);
	}
	else if (s_a)
	{
		ft_stackrev_rotate(&s_a);
		write(1, "rra\n", 4);
	}
	else if (s_b)
	{
		ft_stackrev_rotate(&s_b);
		write(1, "rrb\n", 4);
	}
}
