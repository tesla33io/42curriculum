#include "../libft.h"

int	test_memchr(const void *src, char c, size_t n)
{
	g_num_test++;
	if (ft_memchr(src, c, n) == memchr(src, c, n))
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}