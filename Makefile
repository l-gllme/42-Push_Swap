# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 18:13:28 by lguillau          #+#    #+#              #
#    Updated: 2022/01/11 17:30:43 by lguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c \
		srcs/global_tools.c \
		srcs/parsing/parsing_tools.c \
		srcs/parsing/main_parsing.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	push_swap

CC	=	clang

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

${NAME}:	${OBJS}
		make -C libft
		${CC} ${OBJS} libft/libft.a -o ${NAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}


clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

libfclean:	
		make -C libft fclean

aclean:	fclean libfclean

		
re:		libfclean fclean all


.PHONY:		all clean fclean re libfclean aclean
