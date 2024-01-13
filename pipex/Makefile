# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 17:41:42 by astavrop          #+#    #+#              #
#    Updated: 2024/01/13 13:10:57 by astavrop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					= cc
CFLAGS				= -Wall -Werror -Wextra -g
LIBS				= -L. -lftprintf
NAME				= pipex

SRCS				= check_input.c pipex.c parse.c pipex_utils.c \
						ft_calloc.c ft_memset.c ft_split.c ft_strdup.c
OBJS				= $(SRCS:.c=.o)

FT_PINTF_PATH		= ./ft_printf
FT_PINTF_BIN		= libftprintf.a

all: $(NAME)

.DEFAULT_GOAL := all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): compile-ft-printf $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

compile-ft-printf:
	cd $(FT_PINTF_PATH) && $(MAKE)
	cp $(FT_PINTF_PATH)/$(FT_PINTF_BIN) ./

fclean-ft-printf:
	cd $(FT_PINTF_PATH) && $(MAKE) fclean
	rm -f $(FT_PINTF_BIN)

.PHONY: all clean fclean re compile-ft-printf fclean-ft-printf

clean:
	rm -f $(OBJS)

fclean: clean fclean-ft-printf
	rm -f $(NAME)

re: fclean all