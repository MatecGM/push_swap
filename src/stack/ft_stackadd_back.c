/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:41:34 by mbico             #+#    #+#             */
/*   Updated: 2024/02/24 12:25:30 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_back(t_stack **s, t_stack *new)
{
	t_stack	*tmp;

	if (*s == NULL)
	{
		*s = new;
		return ;
	}
	tmp = *s;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
