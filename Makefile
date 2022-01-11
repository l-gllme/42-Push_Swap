# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 18:13:28 by lguillau          #+#    #+#              #
#    Updated: 2022/01/11 15:05:31 by lguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c \
		srcs/global_tools.c \
		srcs/parsing/check_av.c \
		srcs/parsing/ft_split.c \
		srcs/parsing/parsing.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	push_swap

CC	=	clang

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

${NAME}:	${OBJS}
		${CC} ${OBJS} -o ${NAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}


clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all


.PHONY:		all clean fclean re
