#include "../libft.h"

int	test_memcmp(const void *s1, const void *s2, size_t n)
{
	g_num_test++;
	if (ft_memcmp(s1, s2, n) == memcmp(s1, s2, n))
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}