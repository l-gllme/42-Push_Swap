/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:26:22 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/11 17:20:25 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	ft_parse(int ac, char **av)
{
	t_stack	stacks;
	char	*joined_string;
	char	**str;
	
	stacks.len_a = 0;
	ft_check_argv(av);
	joined_string = ft_join_argv(ac, av);
	str = ft_split(joined_string, ' ');
	free(joined_string);
	int i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (stacks);
}

char	*ft_join_argv(int ac, char **av)
{
	char	*joined_string;
	int	i;
	
	i = 0;
	joined_string = " ";
	if (ac > 2)
	{
		while (av[++i])
		{
			joined_string = ft_strjoin(joined_string,av[i]);
			joined_string = ft_strjoin(joined_string, " ");
		}
	}
	else
	{
		joined_string = ft_strdup(av[1]);
	}
	return (joined_string);
}
