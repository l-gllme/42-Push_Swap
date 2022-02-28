/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:39:25 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/28 15:25:24 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ra_np(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->len_a < 2)
		return ;
	i = -1;
	tmp = s->stack_a[0];
	while (++i < s->len_a)
		s->stack_a[i] = s->stack_a[i + 1];
	s->stack_a[s->len_a - 1] = tmp;
}

void	rb_np(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->len_b < 2)
		return ;
	i = -1;
	tmp = s->stack_b[0];
	while (++i < s->len_b)
		s->stack_b[i] = s->stack_b[i + 1];
	s->stack_b[s->len_b - 1] = tmp;
}

void	rr_np(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->len_a < 2 || s->len_b < 2)
		return ;
	i = -1;
	tmp = s->stack_a[0];
	while (++i < s->len_a)
		s->stack_a[i] = s->stack_a[i + 1];
	s->stack_a[s->len_a - 1] = tmp;
	i = -1;
	tmp = s->stack_b[0];
	while (++i < s->len_b)
		s->stack_b[i] = s->stack_b[i + 1];
	s->stack_b[s->len_b - 1] = tmp;
}
