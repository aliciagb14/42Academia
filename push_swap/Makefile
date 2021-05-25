# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 09:02:14 by agonzale          #+#    #+#              #
#    Updated: 2021/05/25 16:29:00 by agonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
EXTRA = push_swap.a
SRCS = start.c
OBJS = ${SRCS:.c=.o};
CC = gcc -c
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
all: ${NAME}
${NAME}: ${SRCS}
		${CC} ${CFLAGS} ${SRCS}
		ar rc ${NAME} ${OBJS}
		ranlib ${EXTRA}
clean:
		${RM} ${OBJS}
fclean:	clean
		${RM} ${NAME} ${OBJS}
re: fclean all
.PHONY:     all clean fclean