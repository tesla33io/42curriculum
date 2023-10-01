#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>

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

int	g_num_test = 0;

void	print_ok()
{
	printf(GREEN BOLD "...\tTEST [%d] OK\t...\n" R, g_num_test);
}

void	print_ko()
{
	printf(RED BOLD "...\tTEST [%d] KO\t...\n" R, g_num_test);
}

int	main()
{
	int	fail = 0;

	// ISALPHA
	int	(*ft_is_func)(int) = &ft_isalpha;
	printf(CYAN BOLD "***\tft_isalpha()\t***\n" R);
	fail += test_ft_is(ft_is_func, 'A', 1);
	fail += test_ft_is(ft_is_func, 'a', 1);
	fail += test_ft_is(ft_is_func, '4', 0);
	fail += test_ft_is(ft_is_func, '\0', 0);
	fail += test_ft_is(ft_is_func, '.', 0);
	fail += test_ft_is(ft_is_func, 'z', 1);
	printf("\n");
	g_num_test = 0;

	// ISDIGIT
	ft_is_func = &ft_isdigit;
	printf(CYAN BOLD "***\tft_isdigit()\t***\n" R);
	fail += test_ft_is(ft_is_func, '0', 1);
	fail += test_ft_is(ft_is_func, 'a', 0);
	fail += test_ft_is(ft_is_func, '4', 1);
	fail += test_ft_is(ft_is_func, '\0', 0);
	fail += test_ft_is(ft_is_func, '.', 0);
	fail += test_ft_is(ft_is_func, 'z', 0);
	fail += test_ft_is(ft_is_func, '9', 1);
	printf("\n");
	g_num_test = 0;

	// ISALNUM
	ft_is_func = &ft_isalnum;
	printf(CYAN BOLD "***\tft_isalnum()\t***\n" R);
	fail += test_ft_is(ft_is_func, '0', 1);
	fail += test_ft_is(ft_is_func, 'a', 1);
	fail += test_ft_is(ft_is_func, '4', 1);
	fail += test_ft_is(ft_is_func, '\0', 0);
	fail += test_ft_is(ft_is_func, '.', 0);
	fail += test_ft_is(ft_is_func, 'z', 1);
	fail += test_ft_is(ft_is_func, '9', 1);
	printf("\n");
	g_num_test = 0;

	// ISASCII
	ft_is_func = &ft_isascii;
	printf(CYAN BOLD "***\tft_isascii()\t***\n" R);
	fail += test_ft_is(ft_is_func, '0', 1);
	fail += test_ft_is(ft_is_func, 'a', 1);
	fail += test_ft_is(ft_is_func, '{', 1);
	fail += test_ft_is(ft_is_func, '\0', 1);
	fail += test_ft_is(ft_is_func, '%', 1);
	printf("\n");
	g_num_test = 0;

	// ISPRINT
	ft_is_func = &ft_isprint;
	printf(CYAN BOLD "***\tft_isprint()\t***\n" R);
	fail += test_ft_is(ft_is_func, '0', 1);
	fail += test_ft_is(ft_is_func, 'a', 1);
	fail += test_ft_is(ft_is_func, '{', 1);
	fail += test_ft_is(ft_is_func, '\0', 0);
	fail += test_ft_is(ft_is_func, '%', 1);
	fail += test_ft_is(ft_is_func, '\n', 0);
	fail += test_ft_is(ft_is_func, '\t', 0);
	fail += test_ft_is(ft_is_func, 30, 0);
	printf("\n");
	g_num_test = 0;

	// STRLEN
	int	(*ft_str_func)(char *) = &ft_strlen;
	char	*test_text = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy\
		eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero\
		eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata\
		sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet,";
	printf(CYAN BOLD "***\tft_strlen()\t***\n" R);
	fail += test_ft_str(ft_str_func, "test", strlen("test"));
	fail += test_ft_str(ft_str_func, "Some more text.", strlen("Some more text."));
	fail += test_ft_str(ft_str_func, "", strlen(""));
	fail += test_ft_str(ft_str_func, "\n\n\n\n\t\t\t\t\r\r\r\r", strlen("\n\n\n\n\t\t\t\t\r\r\r\r"));
	fail += test_ft_str(ft_str_func, test_text, strlen(test_text));
	printf("\n");
	g_num_test = 0;

	// FT_MEMSET
	printf(CYAN BOLD "***\tft_memset()\t***\n" R);
	fail += test_ft_memset(10, 'A');
	fail += test_ft_memset(10, 'a');
	fail += test_ft_memset(10, '*');
	fail += test_ft_memset(0, '+');
	fail += test_ft_memset(1000, '_');
	fail += test_ft_memset(1000000, '_');
	printf("\n");
	g_num_test = 0;

	// FT_BZERO
	printf(CYAN BOLD "***\tft_bzero()\t***\n" R);
	fail += test_bzero(10);
	fail += test_bzero(0);
	fail += test_bzero(1);
	fail += test_bzero(2);
	fail += test_bzero(1000000);
	printf("\n");
	g_num_test = 0;

	// FT_MEMCPY
	printf(CYAN BOLD "***\tft_memcpy()\t***\n" R);
	fail += test_memcpy("Hello world!", strlen("Hello world!"));
	fail += test_memcpy("Hello\0world!", strlen("Hello\0world!"));
	fail += test_memcpy("Helloworld!", strlen("Helloworld!") - 2);
	fail += test_memcpy("", 0);
	printf("\n");
	g_num_test = 0;

	// FT_MEMMOVE
	printf(CYAN BOLD "***\tft_memmove()\t***\n" R);
	fail += test_memmove("Hello, world!", strlen("Hello, wor"));
	fail += test_memmove("Tes\0t string", strlen("Tes\0t string"));
	fail += test_memmove("", 0);
	printf("\n");
	g_num_test = 0;

	// FT_STRLCPY
	printf(CYAN BOLD "***\tft_strlcpy()\t***\n" R);
	fail += test_strlcpy("Hello world!");
	fail += test_strlcpy("Hello world! And some other text");
	fail += test_strlcpy("Null terminated\0 text");
	fail += test_strlcpy("Lorem ipsum dolor sit amet, consetetur sadipscing elitr");
	printf("\n");
	g_num_test = 0;

	// FT_STRLCAT
	printf(CYAN BOLD "***\tft_strlcat()\t***\n" R);
	fail += test_strlcat("Hello world!");
	fail += test_strlcat("Hello world! And some other text");
	fail += test_strlcat("Null terminated\0 text");
	fail += test_strlcat("Lorem ipsum dolor sit amet, consetetur sadipscing elitr");
	printf("\n");
	g_num_test = 0;

	// FT_TOUPPER
	printf(CYAN BOLD "***\tft_toupper()\t***\n" R);
	fail += test_toupper('a', 'A');
	fail += test_toupper('z', 'Z');
	fail += test_toupper('f', 'F');
	fail += test_toupper('C', 'C');
	fail += test_toupper('.', '.');
	fail += test_toupper('\0', '\0');
	printf("\n");
	g_num_test = 0;

	// FT_TOLOWER
	printf(CYAN BOLD "***\tft_tolower()\t***\n" R);
	fail += test_tolower('a', 'a');
	fail += test_tolower('Z', 'z');
	fail += test_tolower('F', 'f');
	fail += test_tolower('C', 'c');
	fail += test_tolower('.', '.');
	fail += test_tolower('\0', '\0');
	printf("\n");
	g_num_test = 0;

	// FT_STRCHR
	printf(CYAN BOLD "***\tft_strchr()\t***\n" R);
	char	*test_string = "As the sun set over the shimmering lake, a \
		lone kayaker paddled through the calm waters, guided by the gentle \
		ripples of their own thoughts. The soft bree\%ze carried the scent of \
		pine, and the d1stant call of a loon echoed through the serene wilderness.";
	fail += test_strchr(test_string, 'a');
	fail += test_strchr(test_string, 'l');
	fail += test_strchr(test_string, 'e');
	fail += test_strchr(test_string, ']');
	fail += test_strchr(test_string, '%');
	fail += test_strchr(test_string, '\0');
	fail += test_strchr(test_string, '1');
	fail += test_strchr(test_string, '9');
	printf("\n");
	g_num_test = 0;

	// FT_STRRCHR
	printf(CYAN BOLD "***\tft_strrchr()\t***\n" R);
	fail += test_strrchr(test_string, 'a');
	fail += test_strrchr(test_string, 'l');
	fail += test_strrchr(test_string, 'e');
	fail += test_strrchr(test_string, ']');
	fail += test_strrchr(test_string, '%');
	fail += test_strrchr(test_string, '\0');
	fail += test_strrchr(test_string, '1');
	fail += test_strrchr(test_string, '9');
	printf("\n");
	g_num_test = 0;

	// FT_STRNCMP
	printf(CYAN BOLD "***\tft_strncmp()\t***\n" R);
	fail += test_strncmp("q50FW4Q1fB4hjU", "q50FW4Q1fB4hjU", 12);
	fail += test_strncmp("2BZzTpUxISzpUX", "2B42TpUxISzpUX", 2);
	fail += test_strncmp("2BZzTpUxISzpUX", "2B42TpUxISzpUX", 12);
	fail += test_strncmp("F3sTAc5zI4JIqv", "F3sTAc5zI4JIqv", 0);
	fail += test_strncmp("DhpDBPqIk4oyCW", "DhpDBPqIk4oyCW", 20);
	fail += test_strncmp("DhpDBPqIk4oyCW", "DhpDBPqIk4oyCWDhpDBPqIk4oyCW", 20);
	fail += test_strncmp("R5xeVkiCDGHa8TR5xeVkiCDGHa8T", "R5xeVkiCDGHa8T", 20);
	fail += test_strncmp("8jilqVVRBpgv0m", "8jilqVVRBpgv0m", 14);
	printf("\n");
	g_num_test = 0;

	// FT_MEMCHR
	printf(CYAN BOLD "***\tft_memchr()\t***\n" R);
	fail += test_memchr("q50FW4Q1fB4hjU", 'Q', 12);
	fail += test_memchr("P5IVlulSZKvdYO", 'Q', 12);
	fail += test_memchr("qfKtiM1kn5Is8i", '\0', 15);
	fail += test_memchr("eI9ov4tuMEzPUc", 'P', 15);
	fail += test_memchr("1d3uscViRqo8QT", 'T', 12);
	printf("\n");
	g_num_test = 0;

	if (fail > 0)
		printf(RED BOLD "\n\n[%d] KO Error!\n" R, fail);
	else
		printf(GREEN BOLD "\n\nOK. All tests passed!\n" R);
	return (0);
}