/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:35:19 by mbico             #+#    #+#             */
/*   Updated: 2024/02/24 12:25:30 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackpush(t_stack **s1, t_stack **s2)
{
	t_stack	*tmp;

	if (!s1 || !*s1)
		return ;
	tmp = (*s1)->next;
	(*s1)->next = *s2;
	*s2 = *s1;
	*s1 = tmp;
}
