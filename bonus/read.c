/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:23:17 by lguillau          #+#    #+#             */
/*   Updated: 2022/03/01 14:59:16 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void	quit_clean(char *str, t_stack *s)
{
	ft_free_stacks(s);
	get_next_line(42);
	free(str);
	ft_error();
}

static void	call_op(t_stack *s, char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		pa_np(s);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb_np(s);
	else if (ft_strcmp(str, "sa\n") == 0)
		sa_np(s);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb_np(s);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss_np(s);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra_np(s);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb_np(s);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr_np(s);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra_np(s);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb_np(s);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr_np(s);
	else
		quit_clean(str, s);
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
	if (ft_is_it_sorted(s->stack_a, s->len_a) && s->len_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
