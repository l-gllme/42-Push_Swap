/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:42:44 by lguillau          #+#    #+#             */
/*   Updated: 2022/03/01 15:12:21 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	int		ret;

	if (argc < 2)
		exit(1);
	stacks = malloc(sizeof(struct s_list) * 1);
	if (!stacks)
		exit(1);
	ret = ft_parse(argv, stacks);
	if (ret == 0)
	{
		free(stacks);
		exit(1);
	}
	if (stacks->len_a == 3)
		ft_sort_3(stacks);
	else if (stacks->len_a == 5 || stacks->len_a == 4)
		ft_sort_5(stacks);
	else
		ft_sort(stacks);
	ft_free_stacks(stacks);
	return (0);
}
