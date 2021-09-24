NAME = push_swap
LIBFT_A = libft.a
EXTRA = push_swap.a
SRCS = start.c five_numbers.c swap.c sort_three_numbers.c utils.c sorting.c sort_a.c	\
		sort_b.c rotate.c rev_rotate.c push.c
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf
all: ${NAME}
${NAME}: ${LIBFT_A} ${SRCS} ${OBJS}
		${CC} -Ilibft ${CFLAGS} ${SRCS} libft.a -o push_swap  
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