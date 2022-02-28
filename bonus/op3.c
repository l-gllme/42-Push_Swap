/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:57:46 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/28 15:25:50 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	sa_np(t_stack *s)
{
	int	tmp;

	if (s->len_a < 2)
		return ;
	tmp = s->stack_a[0];
	s->stack_a[0] = s->stack_a[1];
	s->stack_a[1] = tmp;
}

void	sb_np(t_stack *s)
{
	int	tmp;

	if (s->len_b < 2)
		return ;
	tmp = s->stack_b[0];
	s->stack_b[0] = s->stack_b[1];
	s->stack_b[1] = tmp;
}

void	ss_np(t_stack *s)
{
	int	tmp;

	if (s->len_a < 2 || s->len_b < 2)
		return ;
	tmp = s->stack_a[0];
	s->stack_a[0] = s->stack_a[1];
	s->stack_a[1] = tmp;
	tmp = s->stack_b[0];
	s->stack_b[0] = s->stack_b[1];
	s->stack_b[1] = tmp;
}

void	pa_np(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->len_b == 0)
		return ;
	i = -1;
	tmp = s->stack_b[0];
	while (++i < s->len_b - 1)
		s->stack_b[i] = s->stack_b[i + 1];
	s->len_b--;
	i = s->len_a;
	while (--i >= 0)
		s->stack_a[i + 1] = s->stack_a[i];
	s->stack_a[0] = tmp;
	s->len_a++;
}

void	pb_np(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->len_a == 0)
		return ;
	i = -1;
	tmp = s->stack_a[0];
	while (++i < s->len_a - 1)
		s->stack_a[i] = s->stack_a[i + 1];
	s->len_a--;
	i = s->len_b;
	while (--i >= 0)
		s->stack_b[i + 1] = s->stack_b[i];
	s->stack_b[0] = tmp;
	s->len_b++;
}
