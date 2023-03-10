# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 03:18:57 by clacaill          #+#    #+#              #
#    Updated: 2023/03/09 17:00:52 by clacaill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version = release letting it empty
build		:=

#Compilation of the push_swap program
NAME    	= push_swap
SRCS_DIR	= ./
SRCS		= main.c checker.c utils_stack.c
SRCS		+= utils/init.c utils/add_lst.c utils/free.c utils/init_2.c
SRCS		+= process/process.c
SRCS		+= process/process_big.c process/process_big_two.c
SRCS		+= process/process_three.c process/process_four.c
SRCS		+= process/process_five.c process/process_six.c
OBJS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.o})
DEPS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.d})

CC			= cc
CLIB		= -Llibft -lft

#Rules for calling of other Makefiles
RM			= rm -rf

#Conditionnal flags depending on the building version
cflags.release	:= -Wall -Wextra -Werror -MMD -MP -g3
cflags.gdb		:= -g
cflags.sanitize	:= -g -fsanitize=address
CFLAGS			:= ${cflags.release} ${cflags.release} ${cflags.${build}}

.c.o	:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#Mandatory rules
${NAME}:${OBJS}
		${MAKE} -C libft
		${CC} ${CFLAGS} ${OBJS} ${CLIB} -o ${NAME}

all:    ${NAME}

#Cleaning rules
clean:
		${RM} ${OBJS} ${DEPS}
		${MAKE} clean -C libft

fclean: clean
		${RM} ${NAME}
		${MAKE} fclean -C libft

re:     fclean
		${MAKE} all

#Dependencies list to be included
-include ${DEPS}

.PHONY: all clean fclean re bonus
