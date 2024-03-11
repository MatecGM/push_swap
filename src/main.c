/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:42:49 by mbico             #+#    #+#             */
/*   Updated: 2024/03/11 15:31:53 by mbico            ###   ########.fr       */
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

void	ft_close(t_vars	*v)
{
	ft_stackclear(v->s_a);
	if (v->s_b)
		ft_stackclear(v->s_b);
	if (v->div)
		free(v->div);
}

int	varsinit(t_vars *v, int argc, char **argv)
{
	v->div = NULL;
	v->s_b = NULL;
	v->s_a = ft_parsing(argc, argv);
	if (!v->s_a)
		return (1);
	v->len = ft_stacklen(v->s_a);
	v->chunk = 4;
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars[1];

	if (varsinit(vars, argc, argv) || !ft_checkdouble(vars->s_a))
	{
		ft_putstr_fd("Error\n", 2);
		ft_close(vars);
		return (1);
	}
	ft_presort(vars);
	if (ft_checker(vars) && vars->len <= 3)
		ft_treesort(vars);
	else if (ft_checker(vars) && vars->len == 5)
		ft_fivesort(vars);
	else if (ft_checker(vars))
	{
		if (vars->len <= 100)
			vars->chunk = 2;
		ft_init_divider(vars);
		ft_stock_on_b(vars);
		count_cost(vars);
		ft_last_rotate(vars);
	}
	ft_close(vars);
}
