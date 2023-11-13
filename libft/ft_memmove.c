/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:28 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/13 12:36:31 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(char *dest, const char *src, size_t n)
{
	unsigned char		*tmp;
	const unsigned char	*source;
	size_t				index;

	tmp = (unsigned char *) dest;
	source = (unsigned char *) src;
	index = n;
	if (*source < *tmp && *tmp < *source + index)
	{
		source += index;
		tmp += index;
		while (index--)
			*(--tmp) = *(--source);
	}
	else
	{
		while (index--)
			*tmp++ = *source++;
	}
	return (tmp);
}