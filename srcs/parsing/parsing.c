/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:26:22 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/11 15:08:41 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	ft_parse(int ac, char **av)
{
	(void)ac;
	t_stack	stacks;

	stacks.len_a = 0;
	//char	*joined_string;
	
	ft_check_argv(av);
	return (stacks);
}
/*	if (ac > 2)
		joined_string = ft_join_argv(**av);
	return (stacks);
}

char	*ft_join_argv(char **av)
{
	char	*joined_string;

	return (joined_string);
}*/
