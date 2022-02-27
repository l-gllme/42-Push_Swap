/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:30:24 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/27 01:01:41 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack *s)
{
	int	i;
	int	tmp;

	write(1, "rra\n", 4);
	if (s->len_a < 2)
		return ;
	tmp = s->stack_a[s->len_a - 1];
	i = s->len_a;
	while (--i > 0)
		s->stack_a[i] = s->stack_a[i - 1];
	s->stack_a[0] = tmp;
}

void	rrb(t_stack *s)
{
	int	i;
	int	tmp;

	write(1, "rrb\n", 4);
	if (s->len_b < 2)
		return ;
	tmp = s->stack_b[s->len_b - 1];
	i = s->len_b;
	while (--i > 0)
		s->stack_b[i] = s->stack_b[i - 1];
	s->stack_b[0] = tmp;
}

void	rrr(t_stack *s)
{
	int	i;
	int	tmp;

	write(1, "rrr\n", 4);
	if (s->len_a < 2 || s->len_b < 2)
		return ;
	tmp = s->stack_a[s->len_a - 1];
	i = s->len_a;
	while (--i > 0)
		s->stack_a[i] = s->stack_a[i - 1];
	s->stack_a[0] = tmp;
	tmp = s->stack_b[s->len_b - 1];
	i = s->len_b;
	while (--i > 0)
		s->stack_b[i] = s->stack_b[i - 1];
	s->stack_b[0] = tmp;
}

void	rra_no_print(int *tab, int len)
{
	int	i;
	int	tmp;

	if (len < 2)
		return ;
	tmp = tab[len - 1];
	i = len;
	while (--i > 0)
		tab[i] = tab[i - 1];
	tab[0] = tmp;
}
