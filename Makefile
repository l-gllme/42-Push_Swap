# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 18:13:28 by lguillau          #+#    #+#              #
#    Updated: 2022/01/24 19:33:05 by lguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	main.c \
		parsing/parsing_tools.c \
		parsing/main_parsing.c \
		tools/tools.c \
		tools/ft_strlen.c \
		tools/ft_split.c \
		tools/ft_atoi.c \
		operations/reverse_rotate.c \
		operations/rotate.c \
		operations/swap_push.c \

S_PATH	=	./srcs/
O_PATH	=	./objs/

SRCS	=	${addprefix ${S_PATH}, ${FILES}}
OBJS	=	${addprefix ${O_PATH}, ${FILES:.c=.o}}

NAME	=	push_swap

CC	=	clang

RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror

${O_PATH}%.o:	${S_PATH}%.c
		@mkdir -p ${dir $@}
		@${CC} ${CFLAGS} -c $< -o $@
		@echo "\e[33mCompiling\e[0m \e[40m$<\e[0m"

${NAME}:	${OBJS}
		@${CC} ${OBJS} -o ${NAME}
		@echo ""
		@echo "\e[36mBuilding\e[0m \e[40m$@\e[0m"
		@echo ""
		@echo "\e[3;32mCompilation is completed !\e[0m"


all:		${NAME}


clean:		
		@${RM} ${O_PATH}
		@echo "\e[91mRemoving\e[0m \e[40m${O_PATH}\e[0m"

fclean:		clean
		@${RM} ${NAME}
		@echo "\e[91mRemoving\e[0m \e[40m${NAME}\e[0m"
		
space:		
		@echo ""

re:		fclean space  all


.PHONY:		all clean fclean re libfclean aclean
