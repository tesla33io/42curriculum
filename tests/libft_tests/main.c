/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:58 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/23 18:06:02 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <time.h>
#include <limits.h>

int	g_num_test = 0;

void	print_ok(void)
{
	printf("...\tTEST [%d] OK\t...\n", g_num_test);
}

void	print_ko(void)
{
	printf("...\tTEST [%d] KO\t...\n^^^^^^^^^^^^^^^^^^^\n\n\n", g_num_test);
}

int	main(void)
{
	// Time setup
	time_t	rawtime;
	struct	tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	int		fail = 0;

	// Print to file setup

	FILE *outputFile = fopen("libft_output.txt", "w"); // Open a file for writing
	if (outputFile == NULL) {
		perror("Failed to open the output file");
		return 1;
	}

	// Redirect stdout to the file
	if (dup2(fileno(outputFile), STDOUT_FILENO) == -1) {
		perror("Failed to redirect stdout to the file");
		return 1;
	}

	printf("Started at %s\n", asctime(timeinfo));
	clock_t begin = clock();

	// ISALPHA
	int	(*ft_is_func)(int) = &ft_isalpha;
	printf("***\tft_isalpha()\t***\n");
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
	printf("***\tft_isdigit()\t***\n");
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
	printf("***\tft_isalnum()\t***\n");
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
	printf("***\tft_isascii()\t***\n");
	fail += test_ft_is(ft_is_func, '0', 1);
	fail += test_ft_is(ft_is_func, 'a', 1);
	fail += test_ft_is(ft_is_func, '{', 1);
	fail += test_ft_is(ft_is_func, '\0', 1);
	fail += test_ft_is(ft_is_func, '%', 1);
	printf("\n");
	g_num_test = 0;

	// ISPRINT
	ft_is_func = &ft_isprint;
	printf("***\tft_isprint()\t***\n");
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
	printf("***\tft_strlen()\t***\n");
	fail += test_ft_str(ft_str_func, "test", strlen("test"));
	fail += test_ft_str(ft_str_func, "Some more text.", strlen("Some more text."));
	fail += test_ft_str(ft_str_func, "", strlen(""));
	fail += test_ft_str(ft_str_func, "\n\n\n\n\t\t\t\t\r\r\r\r", strlen("\n\n\n\n\t\t\t\t\r\r\r\r"));
	fail += test_ft_str(ft_str_func, test_text, strlen(test_text));
	printf("\n");
	g_num_test = 0;

	// FT_MEMSET
	printf("***\tft_memset()\t***\n");
	fail += test_ft_memset(10, 'A');
	fail += test_ft_memset(10, 'a');
	fail += test_ft_memset(10, '*');
	fail += test_ft_memset(0, '+');
	fail += test_ft_memset(1000, '_');
	fail += test_ft_memset(1000000, '_');
	printf("\n");
	g_num_test = 0;

	// FT_BZERO
	printf("***\tft_bzero()\t***\n");
	fail += test_bzero(10);
	fail += test_bzero(0);
	fail += test_bzero(1);
	fail += test_bzero(2);
	fail += test_bzero(100);
	printf("\n");
	g_num_test = 0;

	// FT_MEMCPY
	printf("***\tft_memcpy()\t***\n");
	fail += test_memcpy("Hello world!", strlen("Hello world!"));
	fail += test_memcpy("Hello\0world!", strlen("Hello\0world!"));
	fail += test_memcpy("Helloworld!", strlen("Helloworld!") - 2);
	fail += test_memcpy("", 0);
	printf("\n");
	g_num_test = 0;

	// FT_MEMMOVE
	printf("***\tft_memmove()\t***\n");
	fail += test_memmove("Hello, world!", strlen("Hello, wor"));
	fail += test_memmove("Tes\0t string", strlen("Tes\0t string"));
	fail += test_memmove("", 0);
	printf("\n");
	g_num_test = 0;

	// FT_STRLCPY
	printf("***\tft_strlcpy()\t***\n");
	fail += test_strlcpy("Hello world!");
	fail += test_strlcpy("Hello world! And some other text");
	fail += test_strlcpy("Null terminated\0 text");
	fail += test_strlcpy("Lorem ipsum dolor sit amet, consetetur sadipscing elitr");
	printf("\n");
	g_num_test = 0;

	// FT_STRLCAT
	printf("***\tft_strlcat()\t***\n");
	fail += test_strlcat("Hello world!");
	fail += test_strlcat("Hello world! And some other text");
	fail += test_strlcat("Null terminated\0 text");
	fail += test_strlcat("Lorem ipsum dolor sit amet, consetetur sadipscing elitr");
	printf("\n");
	g_num_test = 0;

	// FT_TOUPPER
	printf("***\tft_toupper()\t***\n");
	fail += test_toupper('a', 'A');
	fail += test_toupper('z', 'Z');
	fail += test_toupper('f', 'F');
	fail += test_toupper('C', 'C');
	fail += test_toupper('.', '.');
	fail += test_toupper('\0', '\0');
	printf("\n");
	g_num_test = 0;

	// FT_TOLOWER
	printf("***\tft_tolower()\t***\n");
	fail += test_tolower('a', 'a');
	fail += test_tolower('Z', 'z');
	fail += test_tolower('F', 'f');
	fail += test_tolower('C', 'c');
	fail += test_tolower('.', '.');
	fail += test_tolower('\0', '\0');
	printf("\n");
	g_num_test = 0;

	// FT_STRCHR
	printf("***\tft_strchr()\t***\n");
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
	printf("***\tft_strrchr()\t***\n");
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
	printf("***\tft_strncmp()\t***\n");
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
	printf("***\tft_memchr()\t***\n");
	fail += test_memchr("q50FW4Q1fB4hjU", 'Q', 12);
	fail += test_memchr("P5IVlulSZKvdYO", 'Q', 12);
	fail += test_memchr("qfKtiM1kn5Is8i", '\0', 15);
	fail += test_memchr("eI9ov4tuMEzPUc", 'P', 15);
	fail += test_memchr("1d3uscViRqo8QT", 'T', 12);
	printf("\n");
	g_num_test = 0;

	// FT_MEMCMP
	printf("***\tft_memcmp()\t***\n");
	fail += test_memcmp("q50FW4QZfB4hjU", "q50FW4QAfB4hjU", 12);						// 1
	fail += test_memcmp("q50FW4Q1fB4hjU", "q50FW4Q1fB4hjU", 0);							// 2
	fail += test_memcmp("q50Fw4Q1fB4hjU", "q50FW4Q1fB4hjZ", 12);						// 3
	fail += test_memcmp("q50FW4Q1fB4hjU", "q50FW4Q1fB4hjZ", 14);						// 4
	fail += test_memcmp("q50FW4Q1fB4hjU", "q50FW4Q1fB4hjU", 24);						// 5
	fail += test_memcmp(&((int[]) {12345, 2, 3, 4, 5}), &((int[]) {1, 2, 3, 4, 5}), 9);	// 6
	fail += test_memcmp(&((int[]) {1, 2, 32, 4, 5}), &((int[]) {1, 2, 3, 4, 6}), 5);	// 7
	fail += test_memcmp(&((int[]) {1, 2, 3, 4, 5}), &((int[]) {1, 200, 3, 4, 5}), 8);	// 8
	fail += test_memcmp(&((int[]) {1, 2, 3, 45, 5}), &((int[]) {1, 2, 3, 4, 5}), 9);	// 9
	fail += test_memcmp(&((int[]) {1, 2, 3234, 4, 5}), &((int[]) {1, 2, 108, 4, 9}), 2);// 10
	fail += test_memcmp(&((int[]) {1, 2, 3, 4, 5}), &((int[]) {1, 2, 3, 4, 9}), 0);		// 11
	printf("\n");
	g_num_test = 0;

	// FT_STRNSTR
	printf("***\tft_strnstr()\t***\n");
	char	*strnstr_text = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut";
	size_t	strnstr_len = strlen(strnstr_text);
	fail += test_strnstr(strnstr_text, "sit", strnstr_len);
	fail += test_strnstr(strnstr_text, ", sed ", strnstr_len);
	fail += test_strnstr(strnstr_text, "ut,", strnstr_len);
	fail += test_strnstr(strnstr_text, " ", strnstr_len);
	fail += test_strnstr(strnstr_text, "", strnstr_len);
	fail += test_strnstr(strnstr_text, "QWEQWE", strnstr_len);
	fail += test_strnstr(strnstr_text, "\\/", strnstr_len);
	printf("\n");
	g_num_test = 0;

	// FT_CALLOC
	printf("***\tft_calloc()\t***\n");
	fail += test_calloc(5, sizeof(int));
	fail += test_calloc(5, sizeof(char));
	fail += test_calloc(5, sizeof(short));
	fail += test_calloc(5, sizeof(long long int));
	fail += test_calloc(CHAR_MAX, sizeof(char));
	fail += test_calloc(5, 0);
	fail += test_calloc(0, 5);
	fail += test_calloc(0, 0);
	printf("\n");
	g_num_test = 0;

	// FT_STRDUP
	char	*strdup_test_string = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, \
		sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam \
		erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea \
		rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum \
		dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, \
		sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam \
		erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea \
		rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum \
		dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed \
		diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, \
		sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. \
		Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit \
		amet. \
		Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie \
		consequat, vel illum dolore eu f";
	printf("***\tft_strdup()\t***\n");
	fail += test_strdup("Test string.");
	fail += test_strdup("Test st\0ring.");
	fail += test_strdup("\n\rTest \tstring\v.");
	fail += test_strdup("");
	fail += test_strdup(" ");
	fail += test_strdup("\r");
	fail += test_strdup(strdup_test_string);
	printf("\n");
	g_num_test = 0;

	// FT_SUBSTR
	printf("***\tft_substr()\t***\n");
	fail += test_ft_substr("This is test string...", 5, 7, "is test");
	fail += test_ft_substr("This is test string...", 0, 7, "This is");
	fail += test_ft_substr("This is test string...", 15, 7, "ring...");
	fail += test_ft_substr("This is test string...", 0, 42000, \
		"This is test string...");
	fail += test_ft_substr("This is test string...", 0, 0, "");
	fail += test_ft_substr("This is test string...", 100, 0, "");
	fail += test_ft_substr("0123456789", 9, 10, "9");
	fail += test_ft_substr("", 0, 0, "");
	fail += test_ft_substr("", 10, 0, "");
	fail += test_ft_substr("", 0, 10, "");
	fail += test_ft_substr("", 10, 10, "");
	printf("\n");
	g_num_test = 0;

	// FT_STRJOIN
	printf("***\tft_strjoin()\t***\n");
	fail += test_ft_strjoin("a", "b", "ab");
	fail += test_ft_strjoin("ab", "bc", "abbc");
	fail += test_ft_strjoin("ab\tcd", "ef\tghi", "ab\tcdef\tghi");
	fail += test_ft_strjoin("", "", "");
	fail += test_ft_strjoin("", " ", " ");
	fail += test_ft_strjoin(" ", "", " ");
	fail += test_ft_strjoin(" ", " ", "  ");
	fail += test_ft_strjoin(" \r", " \r", " \r \r");
	fail += test_ft_strjoin("\n", "\n", "\n\n");
	printf("\n");
	g_num_test = 0;

	// FT_STRTRIM
	char	*strtrim_test_string = "xxx Lorem ipsum dolor sit amet, !!!";
	printf("***\tft_strtrim()\t***\n");
	fail += test_ft_strtrim(strtrim_test_string, "*", \
		"xxx Lorem ipsum dolor sit amet, !!!");
	fail += test_ft_strtrim("aaa bbb ccc ddd", "abcd", "");
	fail += test_ft_strtrim("aaa bbb ccc ddd", "efgh", "");
	fail += test_ft_strtrim("", "abcd", "");
	fail += test_ft_strtrim("this is string", "", "this is string");
	fail += test_ft_strtrim("", "", "");
	fail += test_ft_strtrim(" ", " ", "");
	printf("\n");
	g_num_test = 0;

	// FT_SPLIT
	printf("***\tft_split()\t***\n");
	fail += test_ft_split("some, text, here" , ',', \
		((const char	*[]) {"some", " text", " here", NULL}));
	fail += test_ft_split("some text here", ',', \
		((const char	*[]) {"some text here", NULL}));
	fail += test_ft_split("some   text   here", ' ', \
		((const char	*[]) {"some", "text", "here", NULL}));
	fail += test_ft_split("some text here", 0, \
		((const char	*[]) {"some text here", NULL}));
	fail += test_ft_split("", ' ', \
		((const char	*[]) {NULL}));
	fail += test_ft_split("Tripouille", ' ', \
		((const char	*[]) {"Tripouille", NULL}));
	printf("\n");
	g_num_test = 0;
	// FT_SPLIT

	if (fail > 0)
		printf("\n\n[%d] KO Error!\n", fail);
	else
		printf("\n\nOK. All tests passed!\n");
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent: %f\n", time_spent);
	fclose(outputFile);
	return (0);
}
