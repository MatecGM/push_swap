/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:42:49 by mbico             #+#    #+#             */
/*   Updated: 2024/02/10 16:52:01 by mbico            ###   ########.fr       */
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
	ft_printf("Stock_A\n");
	while (vars->s_a)
	{
		ft_printf("%d = %d\n", vars->s_a->data, vars->s_a->position);
		vars->s_a = vars->s_a->next;
	}
	vars->s_a = s;
	ft_printf("\nStock_B\n");
	ft_init_divider(vars);
	ft_stock_on_b(vars);
	i = 0;
	while (vars->s_b)
	{
		ft_printf("%d\n", vars->s_b->data);
		vars->s_b = vars->s_b->next;
	}
	ft_printf("fin\n");
}
