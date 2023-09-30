#include <string.h>
#include "../libft.h"

int	test_memcpy(char *str, unsigned int n)
{
	char	*source1 = str;
	char	destination1[50];
	char	std_destination1[50];

	// g_num_test++;
	ft_memcpy(destination1, source1, n);
	memcpy(std_destination1, source1, n);
	if (memcmp(destination1, std_destination1, n) == 0)
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}