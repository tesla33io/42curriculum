COMPILER = cc
FLAGS = -Wall -Wextra -Werror
TARGET_NAME = test
SRC_FILES = main.c mem*.c is*.c str*.c bzero.c tests/test_*.c

all: $(TARGET_NAME)

test: $(SRC_FILES)
	$(COMPILER) $(FLAGS) -o $(TARGET_NAME) $(SRC_FILES)

.PHONY: clean
clean:
	rm -f $(TARGET_NAME)