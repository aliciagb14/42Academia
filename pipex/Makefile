NAME = pipex
LIBFT_A = libft.a
EXTRA = pipex.a
SRCS = *.c
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf
all: ${NAME}
${NAME}: ${LIBFT_A} ${SRCS} ${OBJS}
		${CC} -Ilibft ${CFLAGS} ${SRCS} libft.a -o pipex  
${LIBFT_A}:
	make -C libft
	cp libft/libft.a .
clean:
		make -C libft clean
		# ${RM} ${OBJS} libft.a
fclean:	clean
		${RM} ${NAME} ${OBJS}
re: fclean all
.PHONY:     all clean fclean