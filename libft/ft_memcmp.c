#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				result;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	result = (int) n;
	while (*str1 == *str2 && n--)
	{
		str1++;
		str2++;
	}
	if (*str1 < *str2)
		return (-1);
	else if (*str1 > *str2)
		return (result);
	return (0);
}