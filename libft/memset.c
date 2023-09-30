#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*start;
	unsigned char	val;

	i = 0;
	start = s;
	val = (unsigned char)c;
	while (i < n)
	{
		start[i] = val;
		i++;
	}

	return (s);
}
