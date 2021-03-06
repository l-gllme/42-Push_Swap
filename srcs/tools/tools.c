/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:19:46 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/28 18:22:03 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_stacks(t_stack *s)
{
	free(s->stack_a);
	free(s->stack_b);
	free(s);
}

void	ft_full_free(t_stack *s, char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	free(s->stack_a);
	free(s->stack_b);
	free(s);
}

int	ft_is_it_sorted(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (i + j < len)
		{
			if (tab[i] > tab[j + i])
				return (0);
			j++;
		}
		i++;
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
