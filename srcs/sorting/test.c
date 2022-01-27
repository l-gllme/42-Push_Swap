/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:48:11 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/27 16:35:32 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	nbr_ope(int nbra, int nbrb, t_stack *s)
{
	int	rra;
	int	rrb;
	int	i;
	int	j;

	rra = s->len_a - nbra;
	rrb = s->len_b - nbrb;
	i = nbra;
	j = nbrb;
	if (nbra > rra)
		i = rra;
	if (nbrb > rrb)
		j = rrb;
}

static int	how_many_ra(t_stack *s, int *tab)
{
	int	tmp;
	int	i;
	int	nbrb;
	int	nbra;
	int	index;

	tmp = 0;
	nbrb = how_many_rb(s);
	i = -1;
	while (++i < s->len_a - 1)
	{
		nbra = i;
		if (nbr_ope(nbra, nbrb, s))
		{
			tmp = nbr_ope(nbra, nbrb, s);
			index = i;
	}
	return (index);
}

static int	how_many_rb(t_stack *s)
{
	int	count;
	int	i;
	
	
	return ();
}

static void	sort_imgb(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (tab[j] < tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort(t_stack *s)
{
	int	nbra;
	int	nbrb;
	int	i;
	int	j;
	int	*tab;

	i = -1;
	while (++i < s->len_a)
	{
		j = -1;
		tab = malloc(sizeof(int *) * s->len_b);
		while (++j < s->len_b - 1)
			tab[j] = s->stack_b[j];
		sort_imgb(tab, s->len_b);

	}
}
