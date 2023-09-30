#include <string.h>
#include "../libft.h"

int	test_memmove(const char *src, size_t n)
{
	char	destination[100];
	char	std_destination[100];

	g_num_test++;
	ft_memmove(destination, src, n);
	memmove(std_destination, src, n);
	if (memcmp(destination, std_destination, n) == 0)
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}