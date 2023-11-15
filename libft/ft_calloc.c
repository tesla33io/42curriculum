/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:51:27 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/15 17:24:20 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*result;
	size_t			i;
	size_t			j;

	result = malloc(nmemb * size);
	i = 0;
	if (result == NULL)
		return (NULL);
	while (i < nmemb)
	{
		j = 0;
		while (j++ < size)
			result[i] += 0;
		i++;
	}
	return (result);
}
