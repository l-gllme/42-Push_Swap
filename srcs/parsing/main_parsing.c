/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:26:22 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/12 18:38:10 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	ft_parse(int ac, char **av)
{
	t_stack	stacks;

	stacks.len_a = 0;
	ft_check_argv(av);
	stacks = ft_join_argv(av);
	return (stacks);
}

t_stack	*ft_create_stack(char **av)
{
	char *joined_str;
	t_stack stacks;
	char	**str;
	
	joined_str = ft_modified_join(av);
	str = ft_split(joined_string, ' ');
	free(joined_string);
	return (stacks);
}
