/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:19:46 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/12 18:34:17 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_is_it_sorted(int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i] < tab[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_free_char_star_star(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
