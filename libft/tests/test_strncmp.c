#include "../libft.h"
#include <stdio.h>

int	test_strncmp(const char *s1, const char *s2, size_t n)
{
	int	ft_result;
	int	result;

	g_num_test++;
	ft_result = ft_strncmp(s1, s2, n);
	result = strncmp(s1, s2, n);
	printf("ft_result = %d\nstd_result = %d\n",\
		ft_result, result);
	if ((ft_result < 0 && result < 0) \
		|| (ft_result > 0 && result > 0) \
		|| (ft_result == 0 && result == 0))
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}