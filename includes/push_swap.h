/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:19:44 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/12 18:38:48 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "../libft/libft.h"

/* -- Stuct -- */

typedef struct s_list
{
	int	*stack_a;
	int	len_a;
	int	*stack_b;
	int	len_b;

}	t_stack;

/* -- Global Tools -- */

void	ft_error(void);
int	ft_is_it_sorted(int *tab, int len);
void	ft_free_char_star_star(char **str);

/* -- Parsing -- */

t_stack	ft_parse(int ac, char **av);
t_stack *ft_create_stack(char **av);
char	*ft_modified_join(char **str);
int	ft_check_for_alpha(char *s);
void	ft_check_argv(char **av);

#endif
