#include "../libft.h"
#include <bsd/string.h>

int	test_strlcpy(const char *src)
{
	char	dest[50];
	char	bsd_dest[50];
	int		result;
	int		bsd_result;

	g_num_test++;
	result = (int) ft_strlcpy(dest, src, 50);
	bsd_result = (int) strlcpy(bsd_dest, src, 50);
	if (result == bsd_result)
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}