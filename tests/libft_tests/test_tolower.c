#include "libft.h"

int	test_tolower(int c, int expected)
{
	g_num_test++;
	if (ft_tolower(c) == expected)
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}