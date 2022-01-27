/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:34:51 by jtaravel          #+#    #+#             */
/*   Updated: 2022/01/12 17:43:04 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_count_ra(t_stack *global, int *tab)
{
	int	i;
	int	nbra;
	int	nbrb;
	int	tmp;
	int	indexmin;

	i = -1;
	tmp = -1;
	while (++i < global->len_a)
	{
		nbra = i;
		nbrb = ft_number_rb(global, i, tab);
		if (tmp > ft_max(nbra, nbrb, global) || tmp == -1)
		{
			tmp = ft_max(nbra, nbrb, global);
			indexmin = i;
		}
	}
	return (indexmin);
}

int	ft_get_max(int *tab, int size)
{
	int	max;
	int	i;
	int	indexmax;

	i = 0;
	indexmax = 0;
	max = tab[0];
	while (i < size)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			indexmax = i;
		}
		i++;
	}
	return (indexmax);
}

void	ft_inser_base(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
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
