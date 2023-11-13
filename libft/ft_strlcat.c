/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:36 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/13 12:29:37 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	remaining_size;
	size_t	d_len;
	size_t	s_len;
	size_t	cpy_len;

	remaining_size = dstsize;
	s_len = ft_strlen((char *)src);
	while (*dest && remaining_size)
	{
		dest++;
		remaining_size--;
	}
	d_len = dstsize - remaining_size;
	if (d_len < remaining_size)
	{
		cpy_len = remaining_size - 1;
		if (s_len < cpy_len)
			cpy_len = s_len;
		while (*src && cpy_len--)
			*dest++ = *src++;
		*dest = '\0';
	}
	return (d_len + s_len);
}