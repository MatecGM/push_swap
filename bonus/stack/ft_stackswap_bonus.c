/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackswap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:34:46 by mbico             #+#    #+#             */
/*   Updated: 2024/02/29 19:15:58 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_stackswap(t_stack *s)
{
	int	tmp;

	if (s->next)
	{
		tmp = s->data;
		s->data = s->next->data;
		s->next->data = tmp;
	}
}
