/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:26:22 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/12 15:50:30 by lguillau         ###   ########.fr       */
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
	printf("%s\n", joined_string);
	free(joined_string);
	int i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		free(str[i]);
		i++;
	}
	free(str);
	return (stacks);
}

char	*ft_join_argv(int ac, char **av)
{
	char	*joined_string;
	int	i;
	
	i = 0;
	joined_string = malloc(sizeof(char *) * 2);
	if (!joined_string)
		exit(1);
	joined_string[0] = ' ';
	joined_string[1] = 0;
	if (ac > 2)
	{
		while (av[++i])
		{
			printf("1\n");
			joined_string = ft_strjoin(joined_string,av[i]);
			printf("joined str %s\n", joined_string);
			printf("2\n");
			joined_string = ft_strjoin(joined_string, " ");
			printf("joined str %s\n", joined_string);
		}
	}
	else
	{
		joined_string = ft_strdup(av[1]);
	}
	return (joined_string);
}
