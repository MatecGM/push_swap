/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackrev_rotate_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:36:39 by mbico             #+#    #+#             */
/*   Updated: 2024/03/04 10:04:52 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

//1 2 3 4 5 6 -> 6 1 2 3 4 5
void	ft_stackrev_rotate(t_stack **s)
{
	t_stack	*ptr;
	t_stack	*beflast;
	t_stack	*last;

	if (!s || !(*s) || !(*s)->next)
		return ;
	ptr = *s;
	while (ptr->next->next)
		ptr = ptr->next;
	beflast = ptr;
	last = ptr->next;
	beflast->next = NULL;
	last->next = *s;
	*s = last;
}
