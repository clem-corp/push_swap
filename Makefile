# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 03:18:57 by clacaill          #+#    #+#              #
#    Updated: 2023/02/16 03:20:09 by clacaill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
SRC		= main.c ft_checker.c ft_utils_stack.c

OBJS		= ${SRC:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				$(MAKE) all -C libft
				cp libft/libft.a $(NAME)
				ar -rcs ${NAME} ${OBJS}

all:    ${NAME}

clean:
		$(MAKE) clean -C ./libft
		${RM} ${OBJS}

fclean:    clean
		$(MAKE) fclean -C ./libft
		${RM} ${NAME}
        
re:     fclean $(NAME)

.PHONY: all clean fclean re