/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:26:22 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/24 14:52:09 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_parse(char **av, t_stack *stacks)
{
	int	i;
	int	ret;

	i = -1;
	ft_check_argv(av);
	ret = ft_create_stack(av, stacks);
	if (ret == 0)
		return (0);
	if (ft_is_it_sorted(stacks->stack_a, stacks->len_a))
	{
		ft_free_stacks(stacks);
		ft_error();
	}
	if (ft_check_dup(stacks->stack_a, stacks->len_a))
	{
		ft_free_stacks(stacks);
		ft_error();
	}
	return (1);
}

int	ft_create_stack(char **av, t_stack *stacks)
{
	char	*joined_str;
	char	**str;
	int		ret;

	joined_str = ft_modified_join(av);
	if (!joined_str)
		return (0);
	str = ft_split(joined_str, ' ');
	free(joined_str);
	if (!str)
		return (0);
	ret = ft_fill_stack(str, stacks);
	if (ret == 0)
	{
		if (stacks->stack_a)
			free(stacks->stack_a);
		return (0);
	}
	ft_free_char_star_star(str);
	return (1);
}

static	int	ft_char_star_star_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_fill_stack(char **str, t_stack *stacks)
{
	int		i;
	int		len;
	t_lint	nb;

	i = -1;
	len = ft_char_star_star_len(str);
	stacks->stack_a = malloc(sizeof(int *) * len);
	if (!stacks->stack_a)
		return (0);
	stacks->len_a = len;
	stacks->stack_b = malloc(sizeof(int *) * len);
	if (!stacks->stack_b)
		return (0);
	stacks->len_b = 0;
	while (str[++i])
	{
		nb = ft_atoi(str[i]);
		if (nb > 2147483647 || nb < -2147483648)
		{
			ft_free_stacks(stacks);
			ft_error();
		}
		stacks->stack_a[i] = nb;
	}
	return (1);
}
