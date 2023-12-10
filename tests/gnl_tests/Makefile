CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g

NAME			= test
GNL_SRC_PATH	= ../../get_next_line
DEST_PATH		= ./srcs
SRCS			= main.c $(DEST_PATH)/get_next_line.c \
					$(DEST_PATH)/get_next_line_utils.c
OBJS			= $(SRCS:.c=.o)

all: run

.DEFAULT_GOAL := all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# --tool=callgrind for use with kcachegrind
run: sync-files check-files $(NAME)
	valgrind --leak-check=full --track-origins=yes -s ./$(NAME) $(file) | cat -e

check-files:
	@for file in $(GNL_SRC_PATH)/*; do \
		if [ ! -f $$file ]; then \
			echo "$$file not found, copying..."; \
			cp -r $$file $(DEST_PATH)/; \
		fi \
	done

sync-files:
	rsync -u $(GNL_SRC_PATH)/* $(DEST_PATH)/

del-files:
	rm -rf $(DEST_PATH)

clean:
	rm -f $(OBJS)

fclean: clean del-files
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run sync-files check-files del-files
