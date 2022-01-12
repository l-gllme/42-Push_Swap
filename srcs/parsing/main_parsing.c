/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:26:22 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/12 19:08:47 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	ft_parse(int ac, char **av)
{
	t_stack	stacks;

	ft_check_argv(av);
	stacks = ft_create_stack(av);
	return (stacks);
}

static	int	ft_check_for_max_int(char **str)
{
}

t_stack	*ft_create_stack(char **av)
{
	t_stack stacks;
	char *joined_str;
	char	**str;
	
	joined_str = ft_modified_join(av);
	str = ft_split(joined_str, ' ');
	free(joined_str);
	stacks = ft_fill_stack(str);
	ft_free_char_star_star(srt);
	return (stacks);
}

static	int	ft_char_star_star_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_stack	*ft_fill_stack(char **str)
{
	t_stack	stacks;
	int	i;
	int	len;

	len = ft_char_star_star_len(str);
	stacks = malloc(sizeof(t_stack) * 1);
	if (!stacks)
		return (NULL);
	stacks.stack_a = malloc(sizeof(int *) * len);
	if (!stacks.stack_a)
		return (NULL);
	stacks.stack_b = malloc(sizeof(int *) * len);
	if (!stacks.stack_b)
		return (NULL);
	while
	return (stacks);
}
