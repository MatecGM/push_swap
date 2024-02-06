/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:42:49 by mbico             #+#    #+#             */
/*   Updated: 2024/02/06 19:20:25 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_vars	vars[1];

	vars->s_a = ft_parsing(argc, argv);
	vars->len = ft_stacklen(vars->s_a);
	ft_presort(vars);
	while (vars->s_a)
	{
		ft_printf("%d = %d\n", vars->s_a->data, vars->s_a->position);
		vars->s_a = vars->s_a->next;
	}
	ft_printf("fin\n");
}
