/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:42:44 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/17 18:01:54 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stacks;

	if (argc < 2)
		exit(1);
	stacks = ft_parse(argv);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
	return (0);
}
