/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:27:49 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/16 15:30:23 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				result;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	result = (int) n;
	while (*str1 == *str2 && n--)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
	return (0);
}
