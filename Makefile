# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 18:13:28 by lguillau          #+#    #+#              #
#    Updated: 2022/01/07 17:52:07 by lguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	push_swap

CC	=	clang

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror
