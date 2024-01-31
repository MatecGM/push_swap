/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:52:29 by mbico             #+#    #+#             */
/*   Updated: 2024/01/31 19:58:46 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int data)
{
	t_stack	*s;

	s = calloc(1, sizeof(t_stack));
	if (!s)
		return (NULL);
	s->data = data;
	s->next = NULL;
}

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

void	ft_stackpush(t_stack **s1, t_stack **s2)
{
	t_stack *tmp;

	tmp = *s1;
	*s1 = (*s1)->next;
	tmp->next = *s2;
	*s2 = tmp;
}

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
