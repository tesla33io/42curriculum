COMPILER = cc
FLAGS = -Wall -Wextra -Werror -g
TEST_NAME = test
TEST_FILES = main.c test_functions.c test_memcpy.c test_memmove.c test_ftis.c \
	test_ftstr.c test_memcpy.c test_memmove.c test_bzero.c \
	test_memset.c test_strlcpy.c test_strlcat.c test_toupper.c \
	test_tolower.c test_strchr.c test_strrchr.c test_strncmp.c \
	test_memchr.c test_memcmp.c test_strnstr.c test_atoi.c test_calloc.c \
	test_strdup.c test_ft_substr.c test_ft_strjoin.c test_ft_strtrim.c \
	test_ft_split.c test_ft_itoa.c test_ft_strmapi.c test_ft_striteri.c \
	test_ft_putchar_fd.c test_ft_putstr_fd.c test_ft_lstnew.c test_ft_lstadd_front.c \
	test_ft_lstsize.c test_ft_lstlast.c test_ft_lstadd_back.c test_ft_lstdelone.c \
	test_ft_lstclear.c
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
