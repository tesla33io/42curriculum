#include "../libft.h"
#include <stdio.h>

int	test_strncmp(const char *s1, const char *s2, size_t n)
{
	g_num_test++;
	if (ft_strncmp(s1, s2, n) == strncmp(s1, s2, n))
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}