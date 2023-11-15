clear
rm output.txt
make libft.a
make clean
make test
./test
echo ":::Valgrind:::"
valgrind --leak-check=full ./test
echo ":::FCLEAN:::"
make fclean