COMPILER = cc
FLAGS = -Wall -Wextra -Werror -g
TEST_NAME = test
TEST_FILES = main.c test_functions.c test_memcpy.c test_memmove.c test_ftis.c \
	test_ftstr.c test_memcpy.c test_memmove.c test_bzero.c \
	test_memset.c test_strlcpy.c test_strlcat.c test_toupper.c \
	test_tolower.c test_strchr.c test_strrchr.c test_strncmp.c \
	test_memchr.c test_memcmp.c test_strnstr.c test_calloc.c \
	test_strdup.c test_ft_substr.c test_ft_strjoin.c test_ft_strtrim.c \
	test_ft_split.c
TEST_OBJS = $(TEST_FILES:.c=.o)

all: $(TEST_NAME)

.DEFAULT_GOAL := all

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(TEST_NAME): $(TEST_OBJS)
	$(COMPILER) $(FLAGS) $^ -o $@ -L. -lft -lbsd

.PHONY: re

clean:
	rm -f $(TEST_OBJS)

fclean: clean
	rm -f $(TEST_NAME)

re: fclean all
