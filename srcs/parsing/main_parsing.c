/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:26:22 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/17 18:12:36 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_parse(char **av)
{
	t_stack	*stacks;
	int		i;

	i = -1;
	ft_check_argv(av);
	stacks = ft_create_stack(av);
	while (++i < stacks->len_a)
	{
		if (stacks->stack_a[i] > 2147483647 || stacks->stack_a[i] < -2147483648)
		{
			free(stacks->stack_a);
			free(stacks->stack_b);
			free(stacks);
		}
	}
	return (stacks);
}

t_stack	*ft_create_stack(char **av)
{
	t_stack	*stacks;
	char	*joined_str;
	char	**str;

	joined_str = ft_modified_join(av);
	str = ft_split(joined_str, ' ');
	free(joined_str);
	stacks = ft_fill_stack(str);
	ft_free_char_star_star(str);
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
	t_stack			*stacks;
	int				i;
	int				len;
	long long int	nb;

	i = -1;
	stacks = malloc(sizeof(struct s_list) * 1);
	if (!stacks)
		exit(1);
	len = ft_char_star_star_len(str);
	stacks->stack_a = malloc(sizeof(int *) * len);
	if (!stacks->stack_a)
		exit(1);
	stacks->len_a = len;
	stacks->stack_b = malloc(sizeof(int *) * len);
	if (!stacks->stack_b)
		exit(1);
	stacks->len_b = len;
	while (str[++i])
	{
		nb = ft_atoi(str[i]);
		stacks->stack_a[i] = nb;
	}
	return (stacks);
}
