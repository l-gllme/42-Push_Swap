/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:46:18 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/24 14:58:38 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef long long int	t_lint;

size_t	ft_strlen(const char *s);
t_lint	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

#endif
