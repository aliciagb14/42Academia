NAME = push_swap
EXTRA = push_swap.a
SRCS = start.c five_numbers.c swap.c three_numbers.c utils.c sorting.c sort_a.c	\
		sort_b.c rotate.c rev_rotate.c push.c instructions.c inicialize_struct.c
OBJS = ${SRCS:.c=.o};
CC = gcc -c
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
all: ${NAME}
${NAME}: ${SRCS}
		${CC} -Ilibft ${CFLAGS} ${SRCS} libft.a 
		ar rc ${NAME} ${OBJS}
		ranlib ${EXTRA}
clean:
		${RM} ${OBJS}
fclean:	clean
		${RM} ${NAME} ${OBJS}
re: fclean all
.PHONY:     all clean fclean