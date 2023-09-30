COMPILER = cc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
TEST_NAME = test
SRC_FILES = memset.c memcpy.c memmove.c isalnum.c isalpha.c isascii.c isdigit.c isprint.c strlen.c bzero.c
TEST_FILES = main.c tests/test_memcpy.c tests/test_memmove.c
TEST_OBJS = $(TEST_FILES:.c=.o)
OBJS = $(SRC_FILES:.c=.o)

all: $(NAME) $(TEST_NAME)

.DEFAULT_GOAL := all

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

$(TEST_NAME): $(OBJS) $(TEST_OBJS)
	$(COMPILER) $(FLAGS) $^ -o $@

.PHONY: clean fclean

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)
