#include "../libft.h"

int	test_ft_str(int (*func)(char *), char *arg, int excpected)
{
	int	result = 0;

	g_num_test++;
	result = (*func)(arg);
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