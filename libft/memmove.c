#include "libft.h"

void	*ft_memmove(char *dest, const char *src, unsigned int n)
{
	unsigned char		*tmp = (unsigned char *) dest;
	const unsigned char	*source = (unsigned char *) src;

	if (*source < *tmp && *tmp < *source + n)
	{
		source += n;
		tmp += n;
		while (n--)
			*(--tmp) = *(--source);
	}
	else
	{
		while (n--)
			*tmp++ = *source++;
	}
	return (dest);
}