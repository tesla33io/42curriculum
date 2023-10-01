#include "../libft.h"
#include <string.h>

int	test_strchr(const char *str, char c)
{
	g_num_test++;
	if (ft_strchr(str, c) == strchr(str, c))
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}