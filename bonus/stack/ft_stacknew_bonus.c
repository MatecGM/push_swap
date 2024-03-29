/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:34:03 by mbico             #+#    #+#             */
/*   Updated: 2024/02/29 19:15:44 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*ft_stacknew(int data, int position)
{
	t_stack	*s;

	s = calloc(1, sizeof(t_stack));
	if (!s)
		return (NULL);
	s->data = data;
	s->position = position;
	s->next = NULL;
	return (s);
}
