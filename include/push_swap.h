/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:32:06 by mbico             #+#    #+#             */
/*   Updated: 2024/02/24 14:18:33 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

t_stack	*ft_stacknew(int data, int position);
void	ft_stackswap(t_stack *s);
void	ft_stackpush(t_stack **s1, t_stack **s2);
void	ft_stackrotate(t_stack *s);
void	ft_stackrev_rotate(t_stack **s);
void	ft_stackadd_back(t_stack **s, t_stack *new);
int		ft_stacklen(t_stack *s);
t_stack	*ft_parsing(int argc, char **argv);
void	ft_presort(t_vars *v);
void	ft_init_divider(t_vars *v);
void	push(t_stack **s_1, t_stack **s_2, char letter);
void	swap(t_stack *s_a, t_stack *s_b);
void	rotate(t_stack *s_a, t_stack *s_b);
void	revrotate(t_stack **s_a, t_stack **s_b);
void	ft_stock_on_b(t_vars *v);
void	ft_selection(t_vars *v);
int		ft_stack_index(t_stack *s, int pos);
void	count_cost(t_vars *v);
void	ft_last_rotate(t_vars *v);
void	ft_lilpresort(t_vars *v);
void	ft_treesort(t_vars	*v);
void	ft_lilsort(t_vars *v);
void	ft_fivesort(t_vars *v);
void	ft_insertion(t_vars *v);
int		ft_strisint(char *str);
void	ft_stackclear(t_stack *s);
int		ft_checkdouble(t_stack *s);

#endif