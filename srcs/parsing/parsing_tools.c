/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:14:35 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/11 17:06:21 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_check_for_alpha(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '-' && (s[i + 1] < '0' || s[i + 1] > '9'))
			return (1);
		if ((s[i] < '0' || s[i] > '9') && s[i] != ' ' && s[i] != '-')
			return (1);
	}
	return (0);
}

void	ft_check_argv(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_check_for_alpha(av[i]))
			ft_error();
		else
			i++;
	}
}
