# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/09 TRUE0:TRUE7:TRUETRUE by user42            #+#    #+#              #
#    Updated: 2020/09/09 TRUETRUE:58:34 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -c

FUNC = *.c

OBJTS = *.o

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJTS) ft_printf.h
		@gcc -c -I $(CFLAGS) $(FUNC)
		@ar rc $(NAME) $(OBJTS)
		@ranlib $(NAME)

clean:
		@rm -f $(OBJTS)

fclean: clean
		@rm -f $(NAME)

re: fclean all