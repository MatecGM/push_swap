/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:36:03 by mbico             #+#    #+#             */
/*   Updated: 2024/02/04 10:39:30 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//1 2 3 4 5 6 -> 2 3 4 5 6 1
void	ft_stackrotate(t_stack *s)
{
	t_stack	*ptr;
	int		tmp;

	ptr = s;
	tmp = s->data;
	while (ptr->next)
	{
		ptr->data = ptr->next->data;
		ptr = ptr->next;
	}
	ptr->data = tmp;
}
