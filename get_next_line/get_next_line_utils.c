/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:18:17 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/12 10:53:40 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, char c)
{
	char	*s;

	s = (char *) str;
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*join;
	size_t			len;
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	join = (char *)malloc(sizeof(char) * len + 1);
	if (!join)
		return (NULL);
	while (*s1 != '\0')
		join[i++] = *s1++;
	while (*s2 != '\0')
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	result = malloc(nmemb * size);
	if (result != NULL)
	{
		ft_memset(result, 0, nmemb * size);
	}
	return (result);
}
