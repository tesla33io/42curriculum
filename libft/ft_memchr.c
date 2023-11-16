/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:16 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/16 15:30:19 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
