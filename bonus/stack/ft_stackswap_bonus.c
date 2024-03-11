/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackswap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:34:46 by mbico             #+#    #+#             */
/*   Updated: 2024/03/07 13:19:29 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_stackswap(t_stack *s)
{
	int	tmp;

	if (s && s->next)
	{
		tmp = s->data;
		s->data = s->next->data;
		s->next->data = tmp;
	}
}
