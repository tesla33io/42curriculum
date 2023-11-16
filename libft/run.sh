clear
rm output.txt
echo "\e[35m\e[3m"
make libft.a
make clean
make test
./test
echo "\e[0m\e[31m\e[42m:::Valgrind:::\e[0m\e[32m\e[1m"
valgrind --leak-check=full --track-origins=yes ./test
echo "\e[0m\e[31m\e[42m:::FCLEAN:::\e[0m\e[35m\e[3m"
make clean-test
make fclean
echo "\e[0m"