/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:46:18 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/20 14:37:44 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef long long int llint;

size_t	ft_strlen(const char *s);
llint	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

#endif
