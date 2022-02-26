/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:15:01 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/26 13:42:45 by lguillau         ###   ########.fr       */
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

int	iter_a(t_stack *s, int nb)
{
	int	i;
	int	j;

	i = -1;
	j = s->len_a - 1;
	while (++i < s->len_a / 2)
		if (nb > s->stack_a[i] && nb < s->stack_a[i + 1])
			return (i + 1);
	while (--j > s->len_a / 2)
		if (nb < s->stack_a[j] && nb > s->stack_a[j - 1])
			return (j - 1);
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
	while (++i < s->len_a - 1)
	{
		if (s->stack_a[i] > tmp)
		{
			tmp = s->stack_a[i];
			index = i;
		}
	}
	if (index + 1 > s->len_a / 2)
		return (index + 1 - s->len_a);
	return (index + 1);
}

int	find_smallest(int *tmp)
{
	int	nb;
	
	if (tmp[0] == 0 && tmp[1] == 0)
		nb = 0;
	else if (tmp[0] >= 0 && tmp[1] >= 0)
	{
		if (tmp[0] > tmp[1])
			nb = tmp[0];
		else if (tmp[0] < tmp[1])
			nb = tmp[1];
		else
			nb = tmp[0];
	}
	else if (tmp[0] <= 0 && tmp[1] <= 0)
	{
		if (tmp[0] < tmp[1])
			nb = tmp[0] * -1;
		else if (tmp[0] > tmp[1])
			nb = tmp[1] * -1;
		else
			nb = tmp[0] * -1;
	}
	else if (tmp[0] < 0 && tmp[1] > 0)
		nb = tmp[0] * -1 + tmp[1];
	else if (tmp[0] > 0 && tmp[1] < 0)
		nb = tmp[0] + tmp[1] * -1;
	else
		nb = 2147483647;
	return (nb);
}

int	*check_pos_a(t_stack *s, int *ret)
{
	int	i;
	int	nb;
	int	*tmp;

	i = -1;
	ret[0] = 2000000000;
	ret[1] = 2000000000;
	tmp = malloc(sizeof(int) * 2);
	if (!tmp)
		return (0);
	while (++i < s->len_b)
	{
		nb = s->stack_b[i];
		if (i < s->len_b / 2)
			tmp[1] = i;
		else
			tmp[1] = i - s->len_b;
		if (nb > s->stack_a[s->len_a - 1] && nb < s->stack_a[0])
			tmp[0] = 0;
		else if (iter_a(s, nb))
		{
			tmp[0] = iter_a(s, nb);
			if (tmp[0] > s->len_a)
				tmp[0] -= s->len_a;
		}
		else
			tmp[0] = find_max_place(s);
		printf("{%d, %d}\n", tmp[0], tmp[1]);
		if (find_smallest(tmp) < find_smallest(ret))
		{
			ret[0] = tmp[0];
			ret[1] = tmp[1];
		}
	}
	free(tmp);
	return (ret);
}

void	final_sort(int *tmp, t_stack *s)
{
	int	i;

	i = -1;
	if (tmp[0] > 0 && tmp[1] > 0)
	{
		if (tmp[0] == tmp[1])
			while(++i < tmp[0])
				rr(s);
	}
	pa(s);
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
	//find lis
	l = malloc(sizeof(t_lis));
	l = find_lis(tmp, s->len_a, l);
	free(tmp);
	//put not in lis to b
	while (s->len_a > l->l_len)
	{
		if (is_in_lis(s->stack_a[0], l))
			ra(s);
		else
			pb(s);
	}
	free(l->lis);
	free(l);
	//push best in b to a
	tmp = malloc(sizeof(int) * 2);
	tmp = check_pos_a(s, tmp);
	final_sort(tmp, s);
}
