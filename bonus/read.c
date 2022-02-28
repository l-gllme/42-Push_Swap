/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:23:17 by lguillau          #+#    #+#             */
/*   Updated: 2022/03/01 00:27:48 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void	call_op(t_stack *s, char *str)
{
	(void)s;
	if (ft_strcmp(str, "pa") == 0)
		printf("toto");
}

void	checker(t_stack *s)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		call_op(s, str);
		free(str);
		str = get_next_line(0);
	}
	free(str);
}
