#include "../libft.h"
#include <stdio.h>

int	test_ft_str(int (*func)(char *), char *arg, int expected)
{
	int	result = 0;

	g_num_test++;
	result = (*func)(arg);
	printf("arg=[%s], result=[%d], expected=[%d]", arg, result, expected);
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