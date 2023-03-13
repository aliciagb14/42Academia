NAME = push_swap
CC = gcc
SRCS = push.c rotate.c swap.c rev_rotate.c utils.c find_instr.c \
		start.c check_input.c radix_sort.c \
		sort_five_numbers.c sort_three_numbers.c tabs.c
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
all: ${NAME}
${NAME}: ${LIBFT_A} ${SRCS} ${OBJS}
				${CC} -Ilibft ${CFLAGS} ${SRCS} libft.a -o push_swap
${LIBFT_A}: make  -C libft
			cp libft/libft.a
		
clean: make -C libft clean
fclean: clean 
		${RM} ${NAME} ${OBJS}
re: fclean all
	.PHONY: all clean fclean
