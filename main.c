/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:42:49 by mbico             #+#    #+#             */
/*   Updated: 2024/02/13 17:36:39 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_vars	vars[1];
	t_stack	*s;
	int		i;

	vars->s_a = ft_parsing(argc, argv);
	vars->len = ft_stacklen(vars->s_a);
	vars->s_b = NULL;
	s = vars->s_a;
	ft_presort(vars);
	vars->s_a = s;
	ft_init_divider(vars);
	ft_stock_on_b(vars);
	ft_selection(vars);
}
