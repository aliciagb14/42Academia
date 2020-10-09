# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/29 20:57:02 by user42            #+#    #+#              #
#    Updated: 2020/09/29 21:11:20 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -c

FUNC = ft_init.c ft_isspecifier.c ft_printer_char.c ft_printer_string.c ft_printer_hexa.c ft_printer_hexap.c ft_printer_int.c ft_printer_unsigned.c ft_printer.c ft_printf_utils.c ft_printf.c ft_saver_flags.c

OBJTS = ${FUNC:.c=.o}

CFLAGS = 

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