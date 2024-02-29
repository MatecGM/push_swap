/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisint_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:44:22 by mbico             #+#    #+#             */
/*   Updated: 2024/02/29 19:40:25 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static long int	ft_atol(const char *nptr)
{
	long int	nbr;
	long int	sign;

	nbr = 0;
	sign = 1;
	while ((*nptr && *nptr == ' ') || (*nptr && *nptr >= 9 && *nptr <= 13))
		nptr ++;
	if (*nptr && (*nptr == '+' || *nptr == '-'))
	{
		if (*nptr == '-')
			sign = -1;
		nptr ++;
	}
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr * 10 + (*nptr - '0');
		nptr ++;
	}
	nbr *= sign;
	return (nbr);
}

int	ft_strisint(char *str)
{
	int			len;
	long int	nb;
	char		*tmp;

	tmp = str;
	if (*tmp == ' ' || *tmp == '+' || *tmp == '-')
		tmp ++;
	while (*tmp)
	{
		if (*tmp < '0' || *tmp > '9')
			return (0);
		tmp ++;
	}
	len = ft_strlen(str);
	nb = ft_atol(str);
	if (len <= 11 && nb <= 2147483647 && nb >= -2147483648)
		return (1);
	return (0);
}
