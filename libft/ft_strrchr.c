#include "libft.h"

char	*ft_strrchr(const char *str, char c)
{
	char	*s;

	s = NULL;
	while (*str)
	{
		if (*str == c)
			s = (char *) str;
		str++;
	}
	if (*str == c)
		s = (char *) str;
	return (s);
}