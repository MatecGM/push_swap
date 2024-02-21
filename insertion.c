/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:31:29 by mbico             #+#    #+#             */
/*   Updated: 2024/02/21 17:28:50 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static    int maxvalue(t_stack *s, int pos)
{
    int    i;
    t_stack *tmp;
    int    len;

    tmp = s;
    len = ft_stacklen(tmp);
    i = 1;
    while (tmp && tmp->next && tmp->position < tmp->next->position)
    {
        tmp = tmp->next;
        i ++;
    }
    if (!tmp->next && tmp->position < s->position)
        i ++;
    return (i);
}

int  ft_stack_index(t_stack *s, int pos)
{
    int    i;
    t_stack *tmp;
    int    len;

    if (!s || !s->next)
        return (0);
    tmp = s;
    len = ft_stacklen(tmp);
    i = 1;
    while(tmp && tmp->next && !(tmp->position < pos && tmp->next->position > pos))
    {
        i ++;
        tmp = tmp->next;
    }
    if (!tmp->next && !(tmp->position < pos && s->position > pos))
    {
        i = maxvalue(s, pos);
    }
    if (i > len / (double)2)
        i -= len;
    return (i);
}

void	ft_insertion(t_vars *v)
{
	while (v->rot_b < 0)
	{
		revrotate(NULL, &v->s_b);
		v->rot_b ++;
	}
	while (v->rot_b > 0)
	{
		rotate(NULL, v->s_b);
		v->rot_b --;
	}
	while (v->rot_a < 0)
	{
		revrotate(&v->s_a, NULL);
		v->rot_a ++;
	}
	while (v->rot_a > 0)
	{
		rotate(v->s_a, NULL);
		v->rot_a --;
	}
	push(&v->s_b, &v->s_a, 'a');
}