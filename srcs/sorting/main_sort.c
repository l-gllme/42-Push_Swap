/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:15:01 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/27 18:28:46 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_in_lis(int nb, t_lis *l)
{
	int	i;

	i = -1;
	while (++i < l->l_len)
	{
		if (nb == l->lis[i])
			return (1);
	}
	return (0);
}

int	iter_a(t_stack *s, int nb)
{
	int	i;
	int	j;

	i = -1;
	j = s->len_a;
	while (++i < s->len_a / 2)
		if (nb > s->stack_a[i] && nb < s->stack_a[i + 1])
			return (i + 1);
	while (--j > s->len_a / 2)
		if (nb < s->stack_a[j] && nb > s->stack_a[j - 1])
			return (j);
	return (0);
}

int	find_max_place(t_stack *s)
{
	int	i;
	int	index;
	int	tmp;

	index = 0;
	tmp = s->stack_a[0];
	i = -1;
	while (++i < s->len_a)
	{
		if (s->stack_a[i] > tmp)
		{
			tmp = s->stack_a[i];
			index = i;
		}
	}
	if (index == s->len_a - 1)
		return (0);
	if (index > s->len_a / 2)
		return (index + 1 - s->len_a);
	return (index + 1);
}

static void	sort_smallest_in_front(t_stack *s)
{
	int	i;
	int	nb;
	int	index;

	i = -1;
	nb = s->stack_a[0];
	index = 0;
	while (++i < s->len_a)
	{
		if (s->stack_a[i] < nb)
		{
			nb = s->stack_a[i];
			index = i;
		}
	}
	if (index > s->len_a / 2)
		while (s->stack_a[0] != nb)
			rra(s);
	else
		while (s->stack_a[0] != nb)
			ra(s);
}

void	ft_sort(t_stack *s)
{
	int	*tmp;

	main_lis_funct(s);
	tmp = malloc(sizeof(int) * 2);
	while (s->len_b > 0)
	{
		tmp = check_pos_a(s, tmp);
		final_sort(tmp, s);
	}
	free(tmp);
	sort_smallest_in_front(s);
}
