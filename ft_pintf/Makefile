# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 13:26:36 by astavrop          #+#    #+#              #
#    Updated: 2023/12/05 16:52:59 by astavrop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g

NAME		= libftprintf.a
LFT_PATH	= libft
LFT_BIN		= libft.a

SRCS		= src/parser.c ft_printf.c
OBJS		= $(SRCS:.c=.o)

TEST_TARGET	= test
TEST_SRCS	= tests/main.c
TEST_OBJS	= $(TEST_SRCS:.c=.o)

all: $(NAME)

.DEFAULT_GOAL := all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

compile-lft:
	cd $(LFT_PATH) && $(MAKE) bonus
	mv $(LFT_PATH)/$(LFT_BIN) ./

$(NAME): $(OBJS)
	$(MAKE) compile-lft
	ar rcs $@ $^

$(TEST_TARGET): $(TEST_OBJS) $(OBJS)
	$(MAKE) compile-lft
	$(CC) $(CFLAGS) $(TEST_OBJS) $(OBJS) -o $@ -L. -lft -lbsd
	./$(TEST_TARGET)

.PHONY: all clean fclean re clean-lft compile-lft

clean-lft:
	cd $(LFT_PATH) && $(MAKE) fclean

clean: clean-lft
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(LFT_BIN)

re: fclean all
