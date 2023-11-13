/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:02:15 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/13 18:49:52 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	char	*b_clone;
	char	*l_clone;
	char	*start;

	b_clone = big;
	while (*b_clone != '\0' && len--)
	{
		start = b_clone;
		l_clone = little;
		while (*b_clone == *l_clone && *l_clone != '\0')
		{
			b_clone++;
			l_clone++;
		}
		if (*l_clone == '\0')
		{
			return (start);
		}
		b_clone = start + 1;
	}
	return (NULL);
}
