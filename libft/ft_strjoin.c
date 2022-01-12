/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:02:18 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/12 17:26:41 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin2(char *s1, char *s2, char *join)
{
	int	i;

	i = 0;
	while (*s1)
	{
		join[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		join[i] = *s2;
		s2++;
		i++;
	}
	join[i] = 0;
	return (join);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	total_lenght;
	char	*join;

	if (!s1)
	{
		s1 = malloc(sizeof(char *) * 1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	total_lenght = (ft_strlen(s1) + ft_strlen(s2) + 1);
	join = malloc(sizeof(char *) * total_lenght);
	if (!join)
		return (NULL);
	join = ft_strjoin2(s1, s2, join);
	free(s1);
	return (join);
}
