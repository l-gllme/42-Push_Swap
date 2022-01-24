/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:39:25 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/24 16:21:29 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack *s)
{
	int	i;
	int	tmp;

	write(1, "ra\n", 3);
	if (s->len_a < 2)
		return ;
	i = -1;
	tmp = s->stack_a[0];
	while (++i < s->len_a)
		s->stack_a[i] = s->stack_a[i + 1];
	s->stack_a[s->len_a - 1] = tmp;
}

void	rb(t_stack *s)
{
	int	i;
	int	tmp;

	write(1, "rb\n", 3);
	if (s->len_b < 2)
		return ;
	i = -1;
	tmp = s->stack_b[0];
	while (++i < s->len_b)
		s->stack_b[i] = s->stack_b[i + 1];
	s->stack_b[s->len_b - 1] = tmp;
}

void	rr(t_stack *s)
{
	int	i;
	int	tmp;

	write(1, "rr\n", 3);
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
