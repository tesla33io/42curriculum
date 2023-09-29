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

int	g_test_num = 0;

void	*ft_memset(void *s, int c, unsigned int n);
int		ft_isalpha(int c);

void	print_ok()
{
	printf(GREEN BOLD "...\tTEST [%d] OK\t...\n" R, g_test_num);
}

void	print_ko()
{
	printf(RED BOLD "...\tTEST [%d] KO\t...\n" R, g_test_num);
}

int	test_ft_isalpha(char c, int excpected)
{
	int	result = 0;

	g_test_num++;
	result = ft_isalpha(c);
	if (result == excpected)
	{
		print_ok();
		return (0);
	}
	else
	{
		print_ko();
		return (1);
	}
	return (1);
}

int	test_ft_memset(int buf_size, char c)
{
	char	buffer[buf_size];
	char	std_buffer[buf_size];

	g_test_num++;
	ft_memset(buffer, c, sizeof(buffer));

	memset(std_buffer, c, sizeof(std_buffer));

	if (memcmp(buffer, std_buffer, buf_size) == 0)
	{
		print_ok();
		return (0);
	}
	else
	{
		print_ko();
		return (1);
	}
	return (1);
}

int	main()
{
	int	fail = 0;

	// ISALPHA
	printf(CYAN BOLD "***\tft_isalpha()\t***\n" R);
	fail += test_ft_isalpha('A', 1);
	fail += test_ft_isalpha('a', 1);
	fail += test_ft_isalpha('4', 0);
	fail += test_ft_isalpha('\0', 0);
	fail += test_ft_isalpha('.', 0);
	fail += test_ft_isalpha('z', 1);
	g_test_num = 0;

	// FT_MEMSET
	printf(CYAN BOLD "***\tft_memset()\t***\n" R);
	fail += test_ft_memset(10, 'A');
	fail += test_ft_memset(10, 'a');
	fail += test_ft_memset(10, '*');
	fail += test_ft_memset(0, '+');
	fail += test_ft_memset(1000, '_');
	fail += test_ft_memset(1000000, '_');
	g_test_num = 0;

	if (fail > 0)
		printf(RED BOLD "\n\nKO %d Error!\n" R, fail);
	else
		printf(GREEN BOLD "\n\nOK. All tests passed!\n" R);
	return (0);
}