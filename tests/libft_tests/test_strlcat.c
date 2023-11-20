#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>

int	test_strlcat(const char *src)
{
	char	dest[50];
	char	bsd_dest[50];
	size_t	result;
	size_t	bsd_result;

	ft_memset(dest, 0, 50);
	ft_memset(bsd_dest, 0, 50);
	g_num_test++;
	result = ft_strlcat(dest, src, 50);
	bsd_result = strlcat(bsd_dest, src, 50);
	if (memcmp(dest, bsd_dest, 50) == 0 && result == bsd_result)
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}