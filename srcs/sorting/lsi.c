/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:15:01 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/27 17:37:49 by lguillau         ###   ########.fr       */
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

int	is_the_bigger(t_stack *s, int nb)
{
	int	i;

	i = -1;
	while (++i < s->len_a)
		if (nb < s->stack_a[i])
			return (0);
	return (1);
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
		//printf("{%d, %d}\n", tmp[0], tmp[1]);
	}
	free(tmp);
	return (ret);
}

void	final_sort(int *tmp, t_stack *s)
{
	int	i;

	i = 0;
	if (tmp[0] >= 0 && tmp[1] >= 0)
	{
		if (tmp[0] >= tmp[1])
		{
			while(i < tmp[1])
			{
				rr(s);
				i++;
			}
			while (i < tmp[0])
			{
				ra(s);
				i++;
			}
		}
		else if (tmp[0] <= tmp[1])
		{
			while(i < tmp[0])
			{
				rr(s);
				i++;
			}
			while (i < tmp[1])
			{
				rb(s);
				i++;
			}
		}
	}
	else if (tmp[0] <= 0 && tmp[1] <= 0)
	{
		i = 0;
		if (tmp[0] <= tmp[1])
		{
			while (i > tmp[1])
			{
				rrr(s);
				i--;
			}
			while (i > tmp[0])
			{
				rra(s);
				i--;
			}
		}
		else if (tmp[0] >= tmp[1])
		{
			while (i > tmp[0])
			{
				rrr(s);
				i--;
			}
			while (i > tmp[1])
			{
				rrb(s);
				i--;
			}
		}
	}
	else if (tmp[0] <= 0 && tmp[1] >= 0)
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
	else if (tmp[0] >= 0 && tmp[1] <= 0)
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
	pa(s);
}

void	sort_smallest_in_front(t_stack *s)
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
/*
void	ft_sort(t_stack *s)
{
	int	*tmp;
	
	main_lis_funct(s);
	tmp = malloc(sizeof(int) * 2);
	//while (s->len_b > 0)
	//{
		tmp = check_pos_a(s, tmp);
	//	final_sort(tmp, s);
	//}
	free(tmp);
	//sort_smallest_in_front(s);
}
*/
