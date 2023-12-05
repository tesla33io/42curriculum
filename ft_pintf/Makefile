# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 13:26:36 by astavrop          #+#    #+#              #
#    Updated: 2023/12/05 13:29:04 by astavrop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g

NAME	= libftprintf.a

SRCS	=
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

.DEFAULT_GOAL := all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

.PHONY: all clean fclean re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
