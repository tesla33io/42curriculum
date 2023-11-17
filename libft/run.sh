clear
rm output.txt
echo "\e[0m\e[31m\e[42m:::BUILD libft.a:::\e[0m"
echo "\e[35m\e[3m"
make libft.a
echo "\e[0m\e[31m\e[42m:::CLEAN:::\e[0m"
echo "\e[35m\e[3m"
make clean
echo "\e[0m\e[31m\e[42m:::BUILD test:::\e[0m"
echo "\e[35m\e[3m"
make test
# ./test
echo "\e[0m\e[31m\e[42m:::Valgrind:::\e[0m\e[32m\e[1m"
valgrind --leak-check=full --track-origins=yes -s --show-leak-kinds=all ./test
echo "\e[0m\e[31m\e[42m:::FCLEAN:::\e[0m\e[35m\e[3m"
make clean-test
make fclean
echo "\e[0m\e[31m\e[42m:::DONE:::\e[0m"
echo "\e[0m"