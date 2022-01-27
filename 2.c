/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:44:52 by jtaravel          #+#    #+#             */
/*   Updated: 2022/01/12 18:41:16 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_max(int ra, int rb, t_stack *global)
{
	int	tmp;
	int	tmp2;
	int	a;
	int	b;

	if (global->len_a > 0)
		ra = ra % global->len_a;
	if (global->len_b > 0)
		rb = rb % global->len_b;
	a = global->len_a - ra;
	b = global->len_b - rb;
	tmp = ra;
	if (tmp < rb)
		tmp = rb;
	tmp2 = a;
	if (tmp2 < b)
		tmp2 = b;
	if (tmp2 < tmp)
		tmp = tmp2;
	if (tmp > ra + b)
		tmp = ra + b;
	if (tmp > rb + a)
		tmp = rb + a;
	return (tmp);
}

int	ft_number_rb(t_stack *global, int i, int *tab)
{
	int	pos;
	int	j;

	j = -1;
	pos = 0;
	while (++j < global->len_b && tab[j] > global->tab[i])
		pos++;
	return ((ft_get_max(global->tab_b, global->len_b) + pos));
}

void	ft_check_ope(int tmp, int indexmin, int valeur, t_stack *global)
{
	if ((tmp == valeur && valeur >= indexmin)
		|| (tmp == indexmin && indexmin >= valeur))
		ft_rrab(tmp, indexmin, valeur, global);
	else if ((tmp == global->len_b - valeur
			&& (global->len_b - valeur >= global->len_a - indexmin))
		|| (tmp == global->len_a - indexmin
			&& (global->len_a - indexmin >= global->len_b - valeur)))
		ft_rrrab(tmp, indexmin, valeur, global);
	else if (tmp == indexmin + global->len_b - valeur)
		ft_rarrb(tmp, indexmin, valeur, global);
	else
		ft_rrarb(indexmin, valeur, global);
}

void	ft_insertion(int size, t_stack *global)
{
	int	i;
	int	tmp;
	int	valeur;
	int	indexmin;
	int	*test;

	i = -1;
	while (++i < size)
	{
		test = malloc(sizeof(int) * global->len_b);
		tmp = -1;
		while (++tmp < global->len_b)
			test[tmp] = global->tab_b[tmp];
		ft_inser_base(test, tmp);
		indexmin = ft_count_ra(global, test);
		valeur = ft_number_rb(global, indexmin, test);
		if (global->len_b != 0)
			valeur = ft_number_rb(global, indexmin, test) % global->len_b;
		tmp = ft_max(indexmin, valeur, global);
		ft_check_ope(tmp, indexmin, valeur, global);
		free(test);
		ft_pb(global);
	}
	valeur = ft_get_max(global->tab_b, global->len_b);
	ft_repush_a(global, valeur);
}
