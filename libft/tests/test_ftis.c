#include "../libft.h"
#include <stdio.h>

int	test_ft_is(int (*func)(int), int arg, int expected)
{
	int	result = 0;

	g_num_test++;
	result = (*func)(arg);
	printf("arg=%d, result=%d, expected=%d.\n", arg, result, expected);
	if (result == expected)
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