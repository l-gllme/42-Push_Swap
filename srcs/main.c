/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:42:44 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/19 11:52:19 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void sprint(t_stack *stacks)
{
	printf("\n~~ Stacks ~~ \n");
	int i = 0;
	while (i < stacks->len_a)
	{
		printf("~a[%d]=%d\n", stacks->len_a, stacks->stack_a[i]);
		i++;
	}
	i = 0;
	while (i < stacks->len_b)
	{
		printf("~b[%d]=%d\n", stacks->len_b, stacks->stack_b[i]);
		i++;
	}
}

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
	sprint(stacks);
	pb(stacks);	
	pb(stacks);	
	sprint(stacks);
	ft_free_stacks(stacks);
	return (0);
}
