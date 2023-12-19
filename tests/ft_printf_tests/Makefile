# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 16:25:59 by astavrop          #+#    #+#              #
#    Updated: 2023/12/19 17:25:18 by astavrop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g

NAME			= test
FT_PRINTF_PATH	= ../../ft_printf
FT_PRINTF_BIN	= libftprintf.a
SRCS			= main.c
OBJS			= $(SRCS:.c=.o)

all: $(NAME)

.DEFAULT_GOAL := all

$(NAME): $(OBJS)
	cd $(FT_PRINTF_PATH) && $(MAKE)
	cp $(FT_PRINTF_PATH)/$(FT_PRINTF_BIN) ./
	cd $(FT_PRINTF_PATH) && $(MAKE) fclean
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF_BIN)
	valgrind --leak-check=full --show-leak-kinds=all \
		--track-origins=yes -s ./$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(FT_PRINTF_BIN)

re: fclean all

.PHONY: all clean fclean re
