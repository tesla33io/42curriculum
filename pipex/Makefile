# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 17:41:42 by astavrop          #+#    #+#              #
#    Updated: 2024/02/06 20:55:45 by astavrop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					= cc
CFLAGS				= -Wall -Werror -Wextra -g
LIBS				= -L. -lftprintf -lft
NAME				= pipex

SRCS				= check_input.c pipex.c parse_cmds.c pipex_utils.c clear_data.c \
						parse_utils.c parse_args.c execute.c
OBJS				= $(SRCS:.c=.o)

FT_PINTF_PATH		= ./ft_printf
FT_PINTF_BIN		= libftprintf.a

LFT_PATH			= ./libft
LFT_BIN				= libft.a

INFILE				= infile
OUTFILE				= outfile
CMD1				= grep +
CMD2				= wc -l

all: $(NAME)

.DEFAULT_GOAL := all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -s compile-ft-printf
	@$(MAKE) -s compile-lft
	@echo "\n\033[32;49;3m> Compiling code...\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo "\033[32;49;1m>> Done! <<\033[0m"

$(INFILE):
	@echo "\t\tCurtains forcing their will	-\n\
			against the wind,			-\n\
			children sleep,				+\n\
			exchanging dreams with\n\
			seraphim. The city\n\
			drags itself awake on		-\n\
			subway straps; and\n\
			I, an alarm, awake as a		-\n\
			rumor of war,				+\n\
			lie stretching into dawn,\n\
			unasked and unheeded.		-\n" > $(INFILE)
	@echo "\033[33;1mCreate `$(INFILE)` with this content:\033[0m"
	@cat $(INFILE)

test: $(NAME) $(INFILE)
	@echo "\n\n\033[32;4mPipex test:\033[0m"
	@echo "\t \033[0m\033[35;3m./(NAME) (INFILE) \"(CMD1)\" \"(CMD2)\" (OUTFILE)\033[0m"
	@echo "\e[33;1mRunning: \033[0m\033[35;3m./$(NAME) $(INFILE) \"$(CMD1)\" \"$(CMD2)\" $(OUTFILE)\033[0m"
	@./$(NAME) $(INFILE) "$(CMD1)" "$(CMD2)" $(OUTFILE)
	@echo "\e[33;1mRunning: \033[0m\033[35;3mcat $(OUTFILE)\033[0m"
	@echo -n "\033[36m"
	@cat $(OUTFILE)
	@echo -n "\033[0m"

compile-ft-printf:
	@echo "\033[32;49;3m> Making ft_printf...\033[0m"
	@$(MAKE) -C $(FT_PINTF_PATH)
	@cp $(FT_PINTF_PATH)/$(FT_PINTF_BIN) ./
	@echo "\033[32;49;1m> ft_printf ready! <\033[0m"

compile-lft:
	@echo "\n\033[32;49;3m> Making libft...\033[0m"
	@$(MAKE) -C $(LFT_PATH)
	@cp $(LFT_PATH)/$(LFT_BIN) ./
	@echo "\033[32;49;1m> libft ready! <\033[0m"

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
	rm -f $(NAME) $(INFILE) $(OUTFILE)

re: fclean all