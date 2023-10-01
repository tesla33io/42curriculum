#include "libft.h"

void	*ft_memchr(const void *src, char c, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *) src;
	while (*s++ && n--)
	{
		if (*s == c)
			return (s);
	}
	return (NULL);
}