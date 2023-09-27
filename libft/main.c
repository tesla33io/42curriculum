#include "libft.h"
#include <stdio.h>
#include <string.h>

// ANSI escape codes for text colors
#define R "\x1B[0m"		   // Reset color to default
#define RED "\x1B[31m"	   // Red text
#define GREEN "\x1B[32m"   // Green text
#define YELLOW "\x1B[33m"  // Yellow text
#define BLUE "\x1B[34m"	   // Blue text
#define MAGENTA "\x1B[35m" // Magenta text
#define CYAN "\x1B[36m"	   // Cyan text
#define WHITE "\x1B[37m"   // White text

#define BOLD "\x1B[1m"		// Bold text
#define ITALIC "\x1B[3m"	// Italic text
#define UNDERLINE "\x1B[4m" // Underlined text

void *ft_memset(void *s, int c, unsigned int n);

void test_ft_memset(int buf_size, char c, int size, int test_num)
{
	char	buffer[buf_size];
	char	std_buffer[buf_size];
	// char	reset[buf_size];

	printf(BLUE BOLD "....TEST [%d]....\n" R, test_num);
	printf(BLUE "buffer[%d] '%c' %d\n" R, buf_size, c, size);
	printf(MAGENTA "\tft_memset();\n" R);
	ft_memset(buffer, c, size);
	for (int i = 0; i < buf_size; i++)
	{
		printf(YELLOW "|%c|", buffer[i]);
	}
	printf(MAGENTA "\n\tmemset();\n" R);
	memset(std_buffer, c, size);
	for (int i = 0; i < buf_size; i++)
	{
		printf(YELLOW "|%c|", std_buffer[i]);
	}
	if (memcmp(buffer, std_buffer, buf_size) == 0)
		printf(GREEN BOLD "\n....TEST Passed....\n\n" R);
	else
		printf(RED BOLD "\n....TEST Failed....\n\n" R);
	// memcpy(buffer, reset, buf_size);
	// memcpy(std_buffer, reset, buf_size);
}

int main()
{
	printf(CYAN BOLD "***\tft_memset();\t***\n" R);
	test_ft_memset(10, 'A', 5, 1);
	test_ft_memset(10, 'a', 1, 2);
	test_ft_memset(10, '*', 0, 3);
	test_ft_memset(1000, '_', 500, 4);

	return (0);
}