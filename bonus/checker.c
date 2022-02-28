/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:52:45 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/28 16:34:41 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
	checker(stacks);
	ft_free_stacks(stacks);
	return (0);
}
