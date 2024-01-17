# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 17:41:42 by astavrop          #+#    #+#              #
#    Updated: 2024/01/17 18:14:45 by astavrop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					= cc
CFLAGS				= -Wall -Werror -Wextra -g
LIBS				= -L. -lftprintf -lft
NAME				= pipex

SRCS				= check_input.c pipex.c parse_cmds.c pipex_utils.c clear_data.c \
						parse_utils.c
OBJS				= $(SRCS:.c=.o)

FT_PINTF_PATH		= ./ft_printf
FT_PINTF_BIN		= libftprintf.a

LFT_PATH			= ./libft
LFT_BIN				= libft.a

all: $(NAME)

.DEFAULT_GOAL := all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): compile-ft-printf compile-lft $(OBJS)
	@echo "\n\033[32;49;3mCompiling code...\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo "\033[32;49;1mDone!\033[0m"

compile-ft-printf:
	@echo "\033[32;49;3mMaking ft_printf...\033[0m"
	@cd $(FT_PINTF_PATH) && $(MAKE)
	@cp $(FT_PINTF_PATH)/$(FT_PINTF_BIN) ./
	@echo "\033[32;49;1mft_printf ready!\033[0m"

compile-lft:
	@echo "\n\033[32;49;3mMaking libft...\033[0m"
	@cd $(LFT_PATH) && $(MAKE)
	@cp $(LFT_PATH)/$(LFT_BIN) ./
	@echo "\033[32;49;1mlibft ready!\033[0m"

fclean-ft-printf:
	@cd $(FT_PINTF_PATH) && $(MAKE) fclean
	@rm -f $(FT_PINTF_BIN)

fclean-lft:
	@cd $(LFT_PATH) && $(MAKE) fclean
	@rm -f $(LFT_BIN)

.PHONY: all clean fclean re compile-ft-printf fclean-ft-printf compile-lft fclean-lft

clean:
	rm -f $(OBJS)

fclean: clean fclean-ft-printf fclean-lft
	rm -f $(NAME)

re: fclean all