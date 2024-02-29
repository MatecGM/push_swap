/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:27:15 by mbico             #+#    #+#             */
/*   Updated: 2024/02/29 21:29:34 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_checker(t_vars *v)
{
	int		i;
	int		first;
	t_stack	*tmp;

	if (!v->s_a)
		return (0);
	i = 2;
	first = v->s_a->data;
	tmp = v->s_a->next;
	while (tmp && first != tmp->data)
	{
		if (tmp->position != i)
			return (1);
		i ++;
		tmp = tmp->next;
	}
	if (v->s_a->position != 1)
		return (1);
	return (0);
}

void	ft_close(t_vars	*v)
{
	ft_stackclear(v->s_a);
	if (v->s_b)
		ft_stackclear(v->s_b);
}

int	ft_checkdouble(t_stack *s)
{
	t_stack	*actual;
	t_stack	*tmp;

	actual = s;
	while (actual)
	{
		tmp = actual->next;
		while (tmp)
		{
			if (actual->data == tmp->data)
				return (0);
			tmp = tmp->next;
		}
		actual = actual->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	v[1];

	if (argc == 1)
		return (0);
	v->s_b = NULL;
	v->s_a = ft_parsing_arg(argc, argv);
	if (!v->s_a || !ft_checkdouble(v->s_a) || ft_parse(v))
	{
		ft_putstr_fd("Error\n", 2);
		ft_close(v);
		return (1);
	}
	ft_presort(v);
	if (ft_checker(v) || v->s_b)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	ft_close(v);
}
