/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:15:01 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/23 17:23:51 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra_no_print(int *tab, int len)
{
	int	i;
	int	tmp;

	if (len < 2)
		return ;
	i = -1;
	tmp = tab[0];
	while (++i < len)
		tab[i] = tab[i + 1];
	tab[len - 1] = tmp;
}

void	rra_no_print(int *tab, int len)
{
	int	i;
	int	tmp;

	if (len < 2)
		return ;
	tmp = tab[len - 1];
	i = len;
	while (--i > 0)
		tab[i] = tab[i - 1];
	tab[0] = tmp;
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

t_lis	*find_lis(int *tmp, int len, t_lis *l)
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
		return (0);
	l->lis = fill_lis(l->lis, l_len, save_pos, tmp);
	l->l_len = l_len;
	while (--l_len >= 0)
	{
		printf("%d\n", l->lis[l_len]);
	}
	return (l);
}

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

void	ft_sort(t_stack *s)
{
	int	*tmp;
	int	i;
	int	index;
	int	nb;
	t_lis	*l;
	
	// Dup stack a in tmp
	tmp = malloc(sizeof(int *) * s->len_a);
	if (!tmp)
		return ;
	i = -1;
	while (++i < s->len_a)
		tmp[i] = s->stack_a[i];
	// Find smallest in tmp  and put it in front
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
	l = malloc(sizeof(t_lis));
	l = find_lis(tmp, s->len_a, l);
	free(tmp);
	while (s->len_a > l->l_len)
	{
		i = 0;
		while (is_in_lis(s->stack_a[i], l) && i < s->len_a)
			i++;
		if (i < s->len_a / 2)
		{
			nb = s->stack_a[i];
			while (s->stack_a[0] != nb)
				ra(s);
			pb(s);
		}
		else
		{
			nb = s->stack_a[i];
			while (s->stack_a[0] != nb)
				rra(s);
			pb(s);
		}
	}
}
