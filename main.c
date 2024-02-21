/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:42:49 by mbico             #+#    #+#             */
/*   Updated: 2024/02/21 19:42:19 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_vars	vars[1];
	t_stack	*s;
	int		i;

	vars->s_a = ft_parsing(argc, argv);
	vars->s_b = NULL;
	vars->len = ft_stacklen(vars->s_a);
	vars->chunk = 2;
	s = vars->s_a;
	ft_presort(vars);
	if (ft_checker(vars) && vars->len <= 3)
		ft_treesort(vars);
	else if (ft_checker(vars) && vars->len == 5)
		ft_fivesort(vars);
	else if (ft_checker(vars))
	{
		if (vars->len <= 100)
			vars->chunk = 2;
		vars->s_a = s;
		ft_init_divider(vars);
		ft_stock_on_b(vars);
		count_cost(vars);
		ft_last_rotate(vars);
	}
}
