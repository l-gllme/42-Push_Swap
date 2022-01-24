/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:57:46 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/24 14:48:30 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack *s)
{
	int	tmp;

	write(1, "sa\n", 3);
	if (stacks->len_a < 2)
		return ;
	tmp = s->stack_a[0];
	s->stack_a[0] = s->stack_a[1];
	s->stack_a[1] = tmp;
}

void	sb(t_stack *s)
{
	int	tmp;

	write(1, "sb\n", 3);
	if (stacks->len_b < 2)
		return ;
	tmp = s->stack_b[0];
	s->stack_b[0] = s->stack_b[1];
	s->stack_b[1] = tmp;
}

void	ss(t_stack *s)
{
	int	tmp;

	write(1, "ss\n", 3);
	if ((stacks->len_a || stacks-<len_b) < 2)
		return ;
	tmp = s->stack_a[0];
	s->stack_a[0] = s->stack_a[1];
	s->stack_a[1] = tmp;
	tmp = s->stack_b[0];
	s->stack_b[0] = s->stack_b[1];
	s->stack_b[1] = tmp;
}

void	pa(t_stack *s)
{
	write(1, "pa\n", 3);
}

void	pb(t_stack *s)
{
	write(1, "pb\n", 3);
}
