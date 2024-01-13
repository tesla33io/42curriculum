/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:31 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/13 12:58:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

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
