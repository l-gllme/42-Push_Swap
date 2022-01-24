# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 18:13:28 by lguillau          #+#    #+#              #
#    Updated: 2022/01/24 16:24:56 by lguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	./main.c \
		parsing/parsing_tools.c \
		parsing/tools.c \
		parsing/main_parsing.c \
		libft/ft_strlen.c \
		libft/ft_split.c \
		libft/ft_atoi.c \
		operations/reverse_rotate.c \
		operations/rotate.c \
		operations/swap_push.c \

SRCS_PATH =	./srcs/
OBJS_PATH =	./objs/

SRCS	=	${addprefix ${SRCS_PATH}, ${FILES}}
OBJS	=	${addprefix ${OBJS_PATH}, ${FILES:.c=.o}}

NAME	=	push_swap

CC	=	clang

RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror

${OBJS_PATH}%.o:${SRCS_PATH}%.c
		mkdir -p ${dir $@}
		${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
		${CC} ${OBJS} -o ${NAME}


all:		${NAME}


clean:		
		${RM} ${OBJS_PATH}

fclean:		clean
		${RM} ${NAME}
		
re:		libfclean fclean all


.PHONY:		all clean fclean re libfclean aclean
