COMPILER = cc
FLAGS = -Wall -Wextra -Werror -g
NAME = libft.a
TEST_NAME = test
SRC_FILES = ft_memset.c ft_memcpy.c ft_memmove.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_strlen.c ft_bzero.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c
TEST_FILES = main.c tests/test_functions.c tests/test_memcpy.c tests/test_memmove.c tests/test_ftis.c \
	tests/test_ftstr.c tests/test_memcpy.c tests/test_memmove.c tests/test_bzero.c \
	tests/test_memset.c tests/test_strlcpy.c tests/test_strlcat.c tests/test_toupper.c \
	tests/test_tolower.c tests/test_strchr.c tests/test_strrchr.c tests/test_strncmp.c \
	tests/test_memchr.c tests/test_memcmp.c tests/test_strnstr.c tests/test_calloc.c \
	tests/test_strdup.c tests/test_ft_substr.c
TEST_OBJS = $(TEST_FILES:.c=.o)
OBJS = $(SRC_FILES:.c=.o)

all: $(NAME) $(TEST_NAME)

.DEFAULT_GOAL := all

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

$(TEST_NAME): $(TEST_OBJS)
	$(COMPILER) $(FLAGS) $^ -o $@ -L. -lft -lbsd

.PHONY: re

clean:
	rm -f $(OBJS)

clean-test:
	rm -f $(TEST_OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all
