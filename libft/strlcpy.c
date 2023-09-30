#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int dstsize)
{
	unsigned int len;

	len = 0;
	while (*(src + len) && --dstsize)
		*dest++ = *(src + len++);
	*dest = '\0';
	while (*(src + len))
		++len;
	return (len);
}