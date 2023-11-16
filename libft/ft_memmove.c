/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:28 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/16 15:51:19 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(char *dest, const char *src, size_t n)
{
	unsigned char		*tmp;
	const unsigned char	*source;

	tmp = (unsigned char *) dest;
	source = (unsigned char *) src;
	if ((source >= tmp) && (source < tmp + n))
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
