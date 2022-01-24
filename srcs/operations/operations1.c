/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:57:46 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/18 20:17:35 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack *s)
{
	int	tmp;

	if (!s->stack_a[0] || !s->stack_a[1])
	{
		write(1, "sa\n", 3);
		return ;
	}
	tmp = s->stack_a[0];
	s->stack_a[0] = s->stack_a[1];
	s->stack_a[1] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *s)
{
	int	tmp;

	if (!s->stack_b[0] || !s->stack_b[1])
	{
		write(1, "sb\n", 3);
		return ;
	}
	tmp = s->stack_b[0];
	s->stack_b[0] = s->stack_b[1];
	s->stack_b[1] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *s)
{
	int	tmp;

	if (!s->stack_a[0] || !s->stack_a[1])
	{
		write(1, "ss\n", 3);
		return ;
	}
	tmp = s->stack_a[0];
	s->stack_a[0] = s->stack_a[1];
	s->stack_a[1] = tmp;
	if (!s->stack_b[0] || !s->stack_b[1])
	{
		write(1, "ss\n", 3);
		return ;
	}
	tmp = s->stack_b[0];
	s->stack_b[0] = s->stack_b[1];
	s->stack_b[1] = tmp;
	write(1, "ss\n", 3);
}

void	pa(t_stack *s)
{
	if (!s->stack_b[0])
	{
		write(1, "pa\n", 3);
		return ;
	}
	s->stack_a = add_first_elem(s->stack_a, s->len_a, s->stack_b[0]);
	s->len_a++;
	s->stack_b = supp_first_elem(s->stack_b, s->len_b);
	s->len_b--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *s)
{
	if (!s->stack_a[0])
	{
		write(1, "pb:\n", 3);
		return ;
	}
	s->stack_b = add_first_elem(s->stack_b, s->len_b, s->stack_a[0]);
	s->len_b++;
	s->stack_a = supp_first_elem(s->stack_a, s->len_a);
	s->len_a--;
	write(1, "pb\n", 3);
}
