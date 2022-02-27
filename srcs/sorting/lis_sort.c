/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 00:40:13 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/27 01:08:37 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_front_smallest(int *tmp, t_stack *s)
{
	int	i;
	int	index;
	int	nb;

	i = -1;
	nb = tmp[0];
	index = 0;
	while (++i < s->len_a)
	{
		if (tmp[i] < nb)
		{
			nb = tmp[i];
			index = i;
		}
	}
	if (index > s->len_a / 2)
		while (tmp[0] != nb)
			rra_no_print(tmp, s->len_a);
	else
		while (tmp[0] != nb)
			ra_no_print(tmp, s->len_a);
}

static int	try_lis(int *tmp, int len)
{
	int	l_len;
	int	nb;

	l_len = 1;
	nb = tmp[len];
	while (--len >= 0)
	{
		if (tmp[len] < nb)
		{
			l_len++;
			nb = tmp[len];
		}
	}
	return (l_len);
}

static int	*fill_lis(int *lis, int l_len, int save_pos, int *tmp)
{
	int	i;

	i = save_pos;
	l_len--;
	lis[l_len] = tmp[save_pos];
	while (save_pos-- >= 0)
	{
		if (tmp[save_pos] < lis[l_len])
		{
			l_len--;
			lis[l_len] = tmp[save_pos];
		}
	}
	return (lis);
}

static void	find_lis(int *tmp, int len, t_lis *l)
{
	int	l_len;
	int	save_pos;
	int	res;

	l_len = 0;
	save_pos = len;
	while (len-- > 0)
	{
		res = try_lis(tmp, len);
		if (l_len < res)
		{
			l_len = res;
			save_pos = len;
		}
	}
	l->lis = malloc(sizeof(int) * (l_len));
	if (!l->lis)
		return ;
	l->lis = fill_lis(l->lis, l_len, save_pos, tmp);
	l->l_len = l_len;
}

void	main_lis_funct(t_stack *s)
{
	int		*tmp;
	int		i;
	t_lis	*l;

	i = -1;
	tmp = malloc(sizeof(int *) * s->len_a);
	if (!tmp)
		return ;
	while (++i < s->len_a)
		tmp[i] = s->stack_a[i];
	push_front_smallest(tmp, s);
	l = malloc(sizeof(t_lis));
	find_lis(tmp, s->len_a, l);
	free(tmp);
	while (s->len_a > l->l_len)
	{
		if (is_in_lis(s->stack_a[0], l))
			ra(s);
		else
			pb(s);
	}
	free(l->lis);
	free(l);
}
