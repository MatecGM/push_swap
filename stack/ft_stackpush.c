/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:35:19 by mbico             #+#    #+#             */
/*   Updated: 2024/02/10 16:53:57 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stackpush(t_stack **s1, t_stack **s2)
{
	t_stack	*tmp;

	tmp = *s1;
	*s1 = (*s1)->next;
	tmp->next = *s2;
	*s2 = tmp;
	ft_printf("test");
	ft_printf("la %d\n", (*s1)->data);
}
