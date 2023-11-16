/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:53:05 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/16 18:53:36 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
s: The string from which to create the substring.
start: The start index of the substring in the
string ’s’.
len: The maximum length of the substring
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	int		i;
	int		s_len;

	s_len = ft_strlen((char *) s);
	new_s = (char *)malloc((len + 1) * sizeof(char));
	if (new_s != NULL && (s_len <= (int) start))
	{
		i = 0;
		while (s[start] != '\0' && len--)
		{
			new_s[i] = s[start];
			i++;
			start++;
		}
		new_s[i] = '\0';
		return (new_s);
	}
	return (NULL);
}
