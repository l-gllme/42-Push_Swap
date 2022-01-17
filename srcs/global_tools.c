/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:19:46 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/17 19:13:22 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_free_stacks(t_stack *s)
{
	free(s->stack_a);
	free(s->stack_b);
	free(s);
}

int	ft_is_it_sorted(int *tab, int len)
{
	int	i;

	i = 0;
	while (tab[i] < tab[i + 1] && i < len - 1)
		i++;
	if (i == len - 1)
		return (1);
	return (0);
}

void	ft_free_char_star_star(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
