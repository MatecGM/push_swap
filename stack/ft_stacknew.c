/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:34:03 by mbico             #+#    #+#             */
/*   Updated: 2024/02/04 10:39:13 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stacknew(int data)
{
	t_stack	*s;

	s = calloc(1, sizeof(t_stack));
	if (!s)
		return (NULL);
	s->data = data;
	s->next = NULL;
}
