/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:48:21 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/25 16:07:02 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort_3(t_stack *s)
{
	int	*t;

	t = s->stack_a;
	if (t[0] > t[1] && t[0] < t[2])
		sa(s);
	else if (t[0] > t[1] && t[1] > t[2])
	{
		sa(s);
		rra(s);
	}
	else if (t[0] > t[1] && t[1] < t[2])
		ra(s);
	else if (t[0] < t[1] && t[1] > t[2] && t[0] < t[2])
	{
		sa(s);
		ra(s);
	}
	else if (t[0] < t[1] && t[1] > t[2])
		rra(s);
	return ;
}

void	ft_sort_5(t_stack *s)
{
	int	tmp;
	int	i;

	while (s->len_a != 3)
	{
		tmp = s->stack_a[0];
		i = 0;
		while (i < s->len_a)
		{
			if (tmp > s->stack_a[i])
				tmp = s->stack_a[i];
			i++;
		
	i	}
}
