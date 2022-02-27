/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:49:46 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/27 18:10:04 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sup_zero(int *tmp, t_stack *s, int i)
{
	if (tmp[0] >= tmp[1])
	{
		while (i < tmp[1])
		{
			rr(s);
			i++;
		}
		i--;
		while (++i < tmp[0])
			ra(s);
	}
	else if (tmp[0] <= tmp[1])
	{
		while (i < tmp[0])
		{
			rr(s);
			i++;
		}
		i--;
		while (++i < tmp[1])
			rb(s);
	}
}

static void	inf_zero(int *tmp, t_stack *s, int i)
{
	if (tmp[0] <= tmp[1])
	{
		while (i > tmp[1])
		{
			rrr(s);
			i--;
		}
		i++;
		while (--i > tmp[0])
			rra(s);
	}
	else if (tmp[0] >= tmp[1])
	{
		while (i > tmp[0])
		{
			rrr(s);
			i--;
		}
		i++;
		while (--i > tmp[1])
			rrb(s);
	}
}

static void	a_inf_zero_b_sup(int *tmp, t_stack *s, int i)
{
	while (i < tmp[1])
	{
		rb(s);
		i++;
	}
	i = 0;
	while (i > tmp[0])
	{
		rra(s);
		i--;
	}
}

static void	a_sup_zero_b_inf(int *tmp, t_stack *s, int i)
{
	while (i < tmp[0])
	{
		ra(s);
		i++;
	}
	i = 0;
	while (i > tmp[1])
	{
		rrb(s);
		i--;
	}
}

void	final_sort(int *tmp, t_stack *s)
{
	int	i;

	i = 0;
	if (tmp[0] >= 0 && tmp[1] >= 0)
		sup_zero(tmp, s, i);
	else if (tmp[0] <= 0 && tmp[1] <= 0)
		inf_zero(tmp, s, i);
	else if (tmp[0] <= 0 && tmp[1] >= 0)
		a_inf_zero_b_sup(tmp, s, i);
	else if (tmp[0] >= 0 && tmp[1] <= 0)
		a_sup_zero_b_inf(tmp, s, i);
	pa(s);
}
