# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 13:26:36 by astavrop          #+#    #+#              #
#    Updated: 2023/12/12 10:40:54 by astavrop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
NAME		= libftprintf.a

SRCS		= src/parser.c ft_printf.c \
				src/formatter_c.c src/formatter_s.c src/formatter_di.c \
				src/formatter_u.c src/formatter_xX.c src/formatter_ptr.c\
				utils/ft_putchar_fd.c utils/ft_putendl_fd.c utils/ft_putnbr_fd.c \
				utils/ft_putstr_fd.c utils/ft_strlen.c utils/ft_strdup.c
OBJS		= $(SRCS:.c=.o)

TEST_TARGET	= test
TEST_SRCS	= tests/main.c
TEST_OBJS	= $(TEST_SRCS:.c=.o)

all: $(NAME)

.DEFAULT_GOAL := all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

$(TEST_TARGET): $(TEST_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(OBJS) -o $@ -L.
	./$(TEST_TARGET)

.PHONY: all clean fclean re fclean-test

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

fclean-test: fclean
	rm -f $(TEST_OBJS) $(TEST_TARGET)

re: fclean all
