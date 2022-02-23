/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:15:01 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/23 12:42:22 by lguillau         ###   ########.fr       */
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

int	*fill_lis(int *lis, int l_len, int save_pos, int *tmp)
{
	int	i;

	i = save_pos;
	while (--l_len >= 0)
	{
		lis[l_len] = tmp[save_pos];
		while 
	}
}

int	try_lis(int *tmp, int len)
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

int	*find_lis(int *tmp, int len)
{
	int	l_len;
	int	save_pos;
	int	res;
	int	*lis;

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
	lis = malloc(sizeof(int) * (l_len + 1));
	if (!lis)
		return (0);
	//save_pos bonne case -- l_len len total
	lis = fill_lis(lis, l_len, save_pos, tmp);
	return (lis);
}

int	main(void)
{
	int	tmp[10] = {0, 4, 6,1,2,10,7,3,8,9};
	int 	len = 10;
	find_lis(tmp, len);
}

void	ft_sort(t_stack *s)
{
	int	*tmp;
	int	i;
	int	index;
	int	nb;
	
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
}
