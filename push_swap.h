/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:32:06 by mbico             #+#    #+#             */
/*   Updated: 2024/01/31 19:55:18 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}				t_stack;


t_stack	*ft_stacknew(int data);
void	ft_stackswap(t_stack *s);
void	ft_stackpush(t_stack **s1, t_stack **s2);
void	ft_stackrotate(t_stack *s);
void	ft_stackrev_rotate(t_stack **s);

#endif