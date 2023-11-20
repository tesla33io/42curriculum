#include "libft.h"
#include <string.h>

int	test_ft_memset(int buf_size, char c)
{
	char	buffer[buf_size];
	char	std_buffer[buf_size];

	g_num_test++;
	ft_memset(buffer, c, sizeof(buffer));

	memset(std_buffer, c, sizeof(std_buffer));

	if (memcmp(buffer, std_buffer, buf_size) == 0)
	{
		print_ok();
		return (0);
	}
	else
	{
		print_ko();
		return (1);
	}
	return (1);
}