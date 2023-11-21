#!/bin/bash

tests_folder="libft_tests"
libft_directory="../libft"  # Replace this with the actual path to the directory containing libft.a

# Text color variables
BLACK='\033[0;30m'
DARK_GRAY='\033[1;30m'
RED='\033[0;31m'
LIGHT_RED='\033[1;31m'
GREEN='\033[4;32m'
LIGHT_GREEN='\033[1;32m'
ORANGE='\033[0;33m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
LIGHT_BLUE='\033[1;34m'
PURPLE='\033[0;35m'
LIGHT_PURPLE='\033[1;35m'
CYAN='\033[36m'
LIGHT_CYAN='\033[1;36m'
LIGHT_GRAY='\033[0;37m'
WHITE='\033[1;37m'

# Text style variables
BOLD='\033[1m'
UNDERLINE='\033[4m'
BLINK='\033[5m'
INVERT='\033[7m'
STRIKETHROUGH='\033[9m'

# Reset to default color and style
NC='\033[0;0m' # No Color


if [ -d "$tests_folder" ]; then
    echo -e "${GREEN}Tests folder exists. Proceeding.${NC}"

    # Execute Makefile in libft directory
    echo -e "${GREEN}Executing Makefile in $libft_directory.${NC}"
    cd "$libft_directory" || exit 1
    echo -e "${PURPLE}" && make && echo -e "${NC}"

    if [ -f "libft.a" ]; then
        # Move libft.a to the tests directory
        echo -e "${GREEN}Moving libft.a to $tests_folder.${NC}\n"
        mv "libft.a" "../tests/$tests_folder/"

        # Run make fclean in the libft directory
        echo -e "${GREEN}Running 'make fclean' in $libft_directory.${NC}"
        echo -e "${YELLOW}" && make fclean && echo -e "${NC}"

        # Execute Makefile in tests directory
        echo -e "${GREEN}Executing Makefile in $tests_folder.${NC}"
        cd "../tests/$tests_folder" || exit 1
        echo -e "${PURPLE}" && make && echo -e "${NC}"

        if [ $? -eq 0 ]; then
            echo -e "${GREEN}Makefile in $tests_folder ran successfully.${NC}"
            # Clean objects
            echo -e "${YELLOW}" && make clean && echo -e "${NC}"

            # Execute the test file with valgrind
            echo -e "${GREEN}Running Valgrind on the test file.${NC}"
            echo -e "${CYAN}"
            valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test 2>&1 | tee valgrind_output.txt
            echo -r "${NC}"
            # Check Valgrind output for errors or leaks
            if grep -q "ERROR SUMMARY: 0 errors from 0 contexts" valgrind_output.txt && grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
                echo -e "${GREEN}Valgrind: No memory leaks or errors.${NC}"
            else
                echo -e "${RED}Valgrind: Memory leaks or errors detected.${NC}"
            fi

            # Restore initial state
            echo -e "${GREEN}Restoring initial state.${NC}"
            echo -e "${YELLOW}"
            rm -f valgrind_output.txt  # Remove Valgrind output file
            rm -f libft.a
            make fclean  # Clean the tests directory
            cd "../$libft_directory" || exit 1
            make fclean  # Clean the libft directory
            echo -e "${NC}"
        else
            echo -e "${RED}Error: Makefile encountered an error in $tests_folder.${NC}"
            exit 1
        fi
    else
        echo -e "${RED}Error: libft.a not found.${NC}"
        exit 1
    fi
else
    echo -e "${RED}Error: Tests folder '$tests_folder' not found.${NC}"
    exit 1
fi
