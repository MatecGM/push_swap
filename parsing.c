/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:05:53 by mbico             #+#    #+#             */
/*   Updated: 2024/02/04 16:37:26 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_spaciser(char **str)
{
	while (**str)
	{
		if (**str >= 9 && **str <= 13)
			str = ' ';
		*str ++;
	}
}

t_stack	*ft_stack_filler(t_stack *s_a, char **splitted)
{
	t_stack	*new;
	int		i;

	i = 0;
	if (!splitted)
		return (NULL);
	while (splitted[i])
	{
		new = ft_stacknew(ft_atoi(splitted[i]));
		if (!new)
			return (NULL);
		ft_stackadd_back(&s_a, new);
		i ++;
	}
	return (s_a);
}

t_stack	*ft_parsing(int argc, char **argv)
{
	int		i;
	char	**splitted;
	t_stack	*s_a;

	i = 1;
	while (i <= argc)
	{
		ft_spaciser(&argv[i]);
		splitted = ft_split(argv[i], ' ');
		s_a = ft_stack_filler(s_a, splitted);
		if (!s_a)
			return (NULL);
		i ++;
	}
	return (s_a);
}
