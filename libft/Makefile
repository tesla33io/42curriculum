COMPILER = cc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
TEST_NAME = test
SRC_FILES = memset.c memcpy.c memmove.c isalnum.c isalpha.c isascii.c isdigit.c \
	isprint.c strlen.c bzero.c strlcpy.c strlcat.c toupper.c tolower.c strchr.c \
	strrchr.c strncmp.c memchr.c
TEST_FILES = main.c tests/test_memcpy.c tests/test_memmove.c tests/test_ftis.c \
	tests/test_ftstr.c tests/test_memcpy.c tests/test_memmove.c tests/test_bzero.c \
	tests/test_memset.c tests/test_strlcpy.c tests/test_strlcat.c tests/test_toupper.c \
	tests/test_tolower.c tests/test_strchr.c tests/test_strrchr.c tests/test_strncmp.c \
	tests/test_memchr.c
TEST_OBJS = $(TEST_FILES:.c=.o)
OBJS = $(SRC_FILES:.c=.o)

all: $(NAME) $(TEST_NAME)

.DEFAULT_GOAL := all

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

$(TEST_NAME): $(OBJS) $(TEST_OBJS)
	$(COMPILER) $(FLAGS) $^ -o $@ -lbsd

.PHONY: clean fclean

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)
