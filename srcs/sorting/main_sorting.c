/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:39:50 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/27 16:37:02 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	cut_sort(t_stack *s, int tmp, int pos)
{
	while (tmp != s->stack_a[0])
	{
		if (pos < s->len_a / 2)
			ra(s);
		else if (pos == 2)
			sa(s);
		else
			rra(s);
	}
	if (s->len_b == 0 && ft_is_it_sorted(s->stack_a, s->len_a))
		return ;
	pb(s);
}

void	ft_sort(t_stack *s)
{
	int	tmp;
	int	pos;
	int	i;

	while (s->len_a != 0)
	{
		tmp = s->stack_a[0];
		i = 0;
		while (i < s->len_a)
		{
			if (tmp > s->stack_a[i])
			{
				tmp = s->stack_a[i];
				pos = i + 1;
			}
			i++;
		}
		cut_sort(s, tmp, pos);
		if (s->len_b == 0 && ft_is_it_sorted(s->stack_a, s->len_a))
			return ;
	}
	while (s->len_b != 0)
		pa(s);
}
