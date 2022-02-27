/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:12:14 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/27 18:26:04 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static	int	cut_find_smallest(int *tmp, int nb, int v)
{
	if (v == 1)
	{
		if (tmp[0] > tmp[1])
			nb = tmp[0];
		else if (tmp[0] < tmp[1])
			nb = tmp[1];
		else
			nb = tmp[0];
	}
	else
	{
		if (tmp[0] < tmp[1])
			nb = tmp[0] * -1;
		else if (tmp[0] > tmp[1])
			nb = tmp[1] * -1;
		else
			nb = tmp[0] * -1;
	}
	return (nb);
}

static int	find_smallest(int *tmp)
{
	int	nb;

	if (tmp[0] == 0 && tmp[1] == 0)
		nb = 0;
	else if (tmp[0] >= 0 && tmp[1] >= 0)
		nb = cut_find_smallest(tmp, 0, 1);
	else if (tmp[0] <= 0 && tmp[1] <= 0)
		nb = cut_find_smallest(tmp, 0, 0);
	else if (tmp[0] < 0 && tmp[1] > 0)
		nb = tmp[0] * -1 + tmp[1];
	else if (tmp[0] > 0 && tmp[1] < 0)
		nb = tmp[0] + tmp[1] * -1;
	else
		nb = 2147483647;
	return (nb);
}

static int	is_the_bigger(t_stack *s, int nb)
{
	int	i;

	i = -1;
	while (++i < s->len_a)
		if (nb < s->stack_a[i])
			return (0);
	return (1);
}

static void	cut_check_pos(t_stack *s, int *tmp, int i, int *ret)
{
	int	nb;

	nb = s->stack_b[i];
	if (i <= s->len_b / 2)
		tmp[1] = i;
	else if (i == 0)
		tmp[1] = i;
	else
		tmp[1] = i - s->len_b;
	if (nb > s->stack_a[s->len_a - 1] && nb < s->stack_a[0])
		tmp[0] = 0;
	else if (!is_the_bigger(s, nb))
	{
		tmp[0] = iter_a(s, nb);
		if (tmp[0] > s->len_a / 2)
			tmp[0] -= s->len_a;
	}
	else
		tmp[0] = find_max_place(s);
	if (find_smallest(tmp) < find_smallest(ret))
	{
		ret[0] = tmp[0];
		ret[1] = tmp[1];
	}
}

int	*check_pos_a(t_stack *s, int *ret)
{
	int	i;
	int	*tmp;

	i = -1;
	ret[0] = 2000000000;
	ret[1] = 2000000000;
	tmp = malloc(sizeof(int) * 2);
	if (!tmp)
		return (0);
	while (++i < s->len_b)
		cut_check_pos(s, tmp, i, ret);
	free(tmp);
	return (ret);
}
