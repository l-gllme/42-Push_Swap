/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:42:44 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/18 20:19:31 by lguillau         ###   ########.fr       */
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
	int i = 0;
	pb(stacks);	
	pb(stacks);	
	pb(stacks);	
	pb(stacks);	
	pa(stacks);	
	pa(stacks);	
	pa(stacks);	
	pa(stacks);	
	while (i < stacks->len_a)
	{
		printf("~a%d~\n", stacks->stack_a[i]);
		i++;
	}
	i = 0;
	while (i < stacks->len_b)
	{
		printf("~b%d~\n", stacks->stack_b[i]);
		i++;
	}
	ft_free_stacks(stacks);
	return (0);
}
