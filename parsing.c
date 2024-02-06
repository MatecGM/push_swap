/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:05:53 by mbico             #+#    #+#             */
/*   Updated: 2024/02/06 19:30:37 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_spaciser(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 9 && str[i] <= 13)
			str[i] = ' ';
		i ++;
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
		new = ft_stacknew(ft_atoi(splitted[i]), 0);
		if (!new)
			return (NULL);
		ft_stackadd_back(&s_a, new);
		i ++;
	}
	return (s_a);
}

void	ft_free_split(char **splitted_char)
{
	int	i;

	i = 0;
	while (splitted_char[i])
	{
		free(splitted_char[i]);
		i ++;
	}
	free(splitted_char);
}

t_stack	*ft_parsing(int argc, char **argv)
{
	int		i;
	char	**splitted;
	t_stack	*s_a;

	i = 1;
	s_a = NULL;
	while (i < argc)
	{
		ft_spaciser(argv[i]);
		splitted = ft_split(argv[i], ' ');
		s_a = ft_stack_filler(s_a, splitted);
		if (!s_a)
			return (NULL);
		i ++;
		ft_free_split(splitted);

	}
	return (s_a);
}
