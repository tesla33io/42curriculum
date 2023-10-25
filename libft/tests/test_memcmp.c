#include "../libft.h"
#include <stdio.h>

int	test_memcmp(const void *s1, const void *s2, size_t n)
{
	g_num_test++;
	printf("ft_memcmp([%s], [%s], %lu) == %d\n", (char *) s1, (char *) s2, n, ft_memcmp(s1, s2, n));
	printf("memcmp([%s], [%s], %lu) == %d\n", (char *) s1, (char *) s2, n, memcmp(s1, s2, n));
	if (ft_memcmp(s1, s2, n) == memcmp(s1, s2, n))
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}