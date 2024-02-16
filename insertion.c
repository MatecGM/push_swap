/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:31:29 by mbico             #+#    #+#             */
/*   Updated: 2024/02/16 18:37:23 by mbico            ###   ########.fr       */
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

static    int midvalue(t_stack *s, int pos)
{
    int    i;
    t_stack *tmp;
    int    len;

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
        ft_printf("min et max");
        i = maxvalue(s, pos);
    }
    if (i > len / (double)2)
        i -= len;
    return (i);
}

int    ft_stack_index(t_stack *s, int pos)
{
    int    i;
    int    first;
    int    len;
    t_stack    *tmp;

    if (!s || !s->next)
        return (0);
    tmp = s;
    i = midvalue(s, pos);
    s = tmp;
    ft_printf("%d\n", i);
    //i = 0;
    return (i);
}

// void	ft_insertion(t_vars *v)
// {
// 	int	i;
//     int len;
//     len = v->len;
// 	while (len >= 1)
// 	{
// 		i = ft_stack_index(v->s_a, v->s_b->position);
// 		while (i < 0)
// 		{
// 			revrotate(&v->s_a, NULL);
// 			i ++;
// 		}
// 		while (i > 0)
// 		{
// 			rotate(v->s_a, NULL);
// 			i --;
// 		}
// 		push(&v->s_b, &v->s_a, 'a');
// 		len --;
// 	}
// }
