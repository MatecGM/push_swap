/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:32:06 by mbico             #+#    #+#             */
/*   Updated: 2024/02/24 17:46:47 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"

typedef struct s_stack
{
	int				data;
	int				position;
	struct s_stack	*next;
}				t_stack;

typedef struct s_vars
{
	t_stack	*s_a;
	t_stack	*s_b;
	int		len;
	int		*div;
	int		chunk;
	int		rot_a;
	int		rot_b;
}				t_vars;

void	ft_stackadd_back(t_stack **s, t_stack *new);
void	ft_stackclear(t_stack *s);
int		ft_stacklen(t_stack *s);
t_stack	*ft_stacknew(int data, int position);
void	ft_stackpush(t_stack **s1, t_stack **s2);
void	ft_stackrev_rotate(t_stack **s);
void	ft_stackrotate(t_stack *s);
void	ft_stackswap(t_stack *s);

#endif