NAME = pipex
EXTRA = pipex.a
SRCS = *.c
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf
all: ${NAME}
${NAME}: ${LIBFT_A} ${SRCS} ${OBJS}
		${CC} ${CFLAGS} ${SRCS} -o pipex  
clean:
		make -C libft clean

fclean:	clean
		${RM} ${NAME} ${OBJS}
re: fclean all
.PHONY:     all clean fclean