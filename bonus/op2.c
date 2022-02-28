/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:30:24 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/28 15:25:36 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	rra_np(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->len_a < 2)
		return ;
	tmp = s->stack_a[s->len_a - 1];
	i = s->len_a;
	while (--i > 0)
		s->stack_a[i] = s->stack_a[i - 1];
	s->stack_a[0] = tmp;
}

void	rrb_np(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->len_b < 2)
		return ;
	tmp = s->stack_b[s->len_b - 1];
	i = s->len_b;
	while (--i > 0)
		s->stack_b[i] = s->stack_b[i - 1];
	s->stack_b[0] = tmp;
}

void	rrr_np(t_stack *s)
{
	int	i;
	int	tmp;

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
