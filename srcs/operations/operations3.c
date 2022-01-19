/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:30:24 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/19 12:29:31 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	*supp_first_elem(int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	return (tab);
}

int	*add_first_elem(int *tab, int len, int nb)
{
	int	i;
	int	tmp;
	int	tmpbis;

	i = 0;
	if (!tab[0])
	{
		tab[0] = nb;
		return (tab);
	}
	tmp = tab[i];
	tab[i] = nb;
	i++;
	while (i < len)
	{
		tmpbis = tab[i];
		tab[i] = tmp;
		tmp = tab[i + 1];
		tab[i + 1] = tmpbis;
		i++;
	}
	return (tab);
}
