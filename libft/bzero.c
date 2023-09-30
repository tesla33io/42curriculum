#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*string;
	size_t	i;

	string = s;
	i = 0;
	while (i < n)
	{
		string[i] = 0;
		i++;
	}
}