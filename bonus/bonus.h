/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:04:36 by lguillau          #+#    #+#             */
/*   Updated: 2022/03/01 00:13:30 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "../includes/push_swap.h"
# include "gnl/get_next_line.h"

/* Silent op */

void	ra_np(t_stack *s);
void	rb_np(t_stack *s);
void	rr_np(t_stack *s);
void	rra_np(t_stack *s);
void	rrb_np(t_stack *s);
void	rrr_np(t_stack *s);
void	sa_np(t_stack *s);
void	sb_np(t_stack *s);
void	ss_np(t_stack *s);
void	pa_np(t_stack *s);
void	pb_np(t_stack *s);

/* read */

void	checker(t_stack *s);

#endif
