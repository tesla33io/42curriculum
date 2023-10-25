#include "../libft.h"
#include "test_functions.h"
#include <string.h>
#include <stdio.h>

int	test_bzero(int i)
{
	char	buffer[i];
	char	std_buffer[i];

	g_num_test++;
	ft_bzero(buffer, sizeof(buffer));
	bzero(std_buffer, sizeof(std_buffer));
	printf("[i=%d]\n", i);
	print_array("after ft_bzero():", &buffer, i);
	print_array("after bzero():", &std_buffer, i);
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