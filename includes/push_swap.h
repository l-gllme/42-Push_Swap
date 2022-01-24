/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:19:44 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/24 16:22:44 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft.h"

/* ~-~-~ Stuct ~-~-~ */

typedef struct s_list
{
	int	*stack_a;
	int	len_a;
	int	*stack_b;
	int	len_b;

}	t_stack;

/* ~-~-~ Global Tools ~-~-~ */

void	ft_error(void);
int		ft_is_it_sorted(int *tab, int len);
void	ft_free_char_star_star(char **str);
void	ft_free_stacks(t_stack *s);

/* ~-~-~ Parsing ~-~-~ */

int		ft_parse(char **av, t_stack *stacks);
int		ft_create_stack(char **av, t_stack *stacks);
int		ft_fill_stack(char **str, t_stack *stacks);
char	*ft_modified_join(char **str);
int		ft_check_for_alpha(char *s);
void	ft_check_argv(char **av);
int		ft_check_dup(int *tab, int len);

/* ~-~-~ Operations ~-~-~ */

void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s);
void	pa(t_stack *s);
void	pb(t_stack *s);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);

#endif
