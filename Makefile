# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 03:18:57 by clacaill          #+#    #+#              #
#    Updated: 2023/02/16 06:29:15 by clacaill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version = release letting it empty
build		:=

#Compilation of the push_swap program
NAME    	= push_swap
SRCS_DIR	= ./
SRCS		= ft_checker.c ft_utils_stack.c main.c
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
CFLAGS			:= ${cflags.release} ${cflags.${build}}

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