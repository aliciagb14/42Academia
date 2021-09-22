NAME = minitalk
LIBFT_A = libft.a
EXTRA = minitalk.a
SRCS = client.c server.c
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
all: ${NAME}
${NAME}: ${LIBFT_A} ${SRCS}
		${CC} -Ilibft ${CFLAGS} ${SRCS} libft.a -o minitalk
${LIBFT_A}:
	make -C libft
	cp libft/libft.a .
clean:
		make -C libft clean
		${RM} ${OBJS} libft.a
fclean:	clean
		${RM} ${NAME} ${OBJS}
re: fclean all
.PHONY:     all clean fclean