# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 18:13:28 by lguillau          #+#    #+#              #
#    Updated: 2022/01/18 15:07:27 by lguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	main.c \
		global_tools.c \
		parsing/parsing_tools.c \
		parsing/main_parsing.c \
		operations/operations.c \
		operations/operations3.c \

SRCS_PATH =	./srcs/
OBJS_PATH =	./objs/

SRCS	=	${addprefix ${SRCS_PATH}, ${FILES}}
OBJS	=	${addprefix ${OBJS_PATH}, ${FILES:.c=.o}}

NAME	=	push_swap

CC	=	clang

RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror

${OBJS_PATH}%.o:${SRCS_PATH}%.c
		@mkdir -p ${dir $@}
		${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
		make -C libft
		${CC} ${OBJS} libft/libft.a -o ${NAME}


all:		${NAME}


clean:		
		${RM} ${OBJS_PATH}

fclean:		clean
		${RM} ${NAME}

libfclean:	
		make -C libft fclean

aclean:		fclean libfclean

		
re:		libfclean fclean all


.PHONY:		all clean fclean re libfclean aclean
