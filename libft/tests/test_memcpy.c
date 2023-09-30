#include <string.h>
void	*ft_memcpy(char *dest, const char *src, unsigned int n);
void	print_ok();
void	print_ko();

int	test_memcpy(char *str, unsigned int n, int *g_test_num)
{
	char	*source1 = str;
	char	destination1[50];
	char	std_destination1[50];

	(*g_test_num)++;
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