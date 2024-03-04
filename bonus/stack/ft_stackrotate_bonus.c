/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackrotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:36:03 by mbico             #+#    #+#             */
/*   Updated: 2024/03/04 10:04:34 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

//1 2 3 4 5 6 -> 2 3 4 5 6 1
void	ft_stackrotate(t_stack *s)
{
	t_stack	*ptr;
	int		tmp_d;
	int		tmp_p;

	if (!s)
		return ;
	ptr = s;
	tmp_d = s->data;
	tmp_p = s->position;
	while (ptr->next)
	{
		ptr->data = ptr->next->data;
		ptr->position = ptr->next->position;
		ptr = ptr->next;
	}
	ptr->data = tmp_d;
	ptr->position = tmp_p;
}
