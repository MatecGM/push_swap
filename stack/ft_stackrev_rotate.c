/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackrev_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:36:39 by mbico             #+#    #+#             */
/*   Updated: 2024/02/04 10:39:33 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//1 2 3 4 5 6 -> 6 1 2 3 4 5
void	ft_stackrev_rotate(t_stack **s)
{
	t_stack	*ptr;

	ptr = *s;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *s;
	*s = (*s)->next;
	ptr->next->next = NULL;
}
