/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:16:53 by mbico             #+#    #+#             */
/*   Updated: 2024/02/29 20:57:16 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_parse(t_vars *v)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		if (ft_intruction_read(v, s))
		{
			free(s);
			close(0);
			return (1);
		}
		free(s);
		s = get_next_line(0);
	}
	close(0);
	return (0);
}
