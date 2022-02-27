# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 18:13:28 by lguillau          #+#    #+#              #
#    Updated: 2022/02/27 01:02:16 by lguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	main.c \
		tools/tools.c \
		tools/ft_atoi.c \
		tools/ft_split.c \
		tools/ft_strlen.c \
		operations/rotate.c \
		operations/r_rotate.c \
		operations/swap_push.c \
		sorting/lsi.c \
		sorting/five_sorting.c \
		sorting/lis_sort.c \
		parsing/main_parsing.c \
		parsing/parsing_tools.c \

S_PATH	=	srcs/
O_PATH	=	objs/

SRCS	=	${addprefix ${S_PATH}, ${FILES}}
OBJS	=	${addprefix ${O_PATH}, ${FILES:.c=.o}}

NAME	=	push_swap

CC	=	clang

RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror

${O_PATH}%.o:	${S_PATH}%.c
		@mkdir -p ${dir $@}
		@${CC} ${CFLAGS} -c $< -o $@
		@echo "\033[33mCompiling\033[0m \033[40m$<\033[0m \033[1;33m->\033[0m \033[94m$@\033[0m"

${NAME}:	${OBJS}
		@${CC} ${OBJS} -o ${NAME}
		@echo ""
		@echo "\033[36mBuilding\033[0m \033[40m$@\033[0m"
		@echo ""
		@echo "\033[3;32mCompilation is completed !\033[0m"

all:		${NAME}

clean:		
		@${RM} ${O_PATH}
		@echo "\033[91mRemoving\033[0m \033[40m${O_PATH}\033[0m"

fclean:		clean
		@${RM} ${NAME}
		@echo "\033[91mRemoving\033[0m \033[40m${NAME}\033[0m"
		
space:		
		@echo ""

re:		fclean space  all

.PHONY:		all clean fclean re
