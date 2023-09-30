#include "../libft.h"
#include <strings.h>
#include <string.h>

int	test_bzero(int i)
{
	char	buffer[i];
	char	std_buffer[i];

	g_num_test++;
	ft_bzero(buffer, sizeof(buffer));
	bzero(std_buffer, sizeof(std_buffer));
	if (memcmp(buffer, std_buffer, i) == 0)
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