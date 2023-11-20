#include "libft.h"

int	test_strrchr(const char *str, char c)
{
	g_num_test++;
	if (ft_strrchr(str, c) == strrchr(str, c))
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}