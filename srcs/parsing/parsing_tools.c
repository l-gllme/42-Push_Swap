/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:14:35 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/28 18:13:36 by lguillau         ###   ########.fr       */
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

void	ft_check_argv(char **av, t_stack *s)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_check_for_alpha(av[i]))
		{
			free(s);
			ft_error();
		}
		else
			i++;
	}
}

static int	ft_total_len(char **str)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[++i])
		len += ft_strlen(str[i]);
	return (len + i);
}

char	*ft_modified_join(char **str)
{
	int		i;
	int		j;
	char	*s1;

	i = 0;
	j = 0;
	s1 = malloc(sizeof(char *) * (ft_total_len(str) + 1));
	if (!s1)
		return (NULL);
	while (str[++i])
	{
		while (*str[i])
		{
			s1[j] = *str[i];
			j++;
			str[i]++;
		}
		s1[j] = ' ';
		j++;
	}
	s1[j] = 0;
	return (s1);
}

int	ft_check_dup(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (tab[i] == tab[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
