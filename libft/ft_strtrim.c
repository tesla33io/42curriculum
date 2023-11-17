/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:01:16 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/17 19:42:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// _in(): check if char `c` is in string `set`.
// return: `c` is in `set` (1) or not in `set` (0).
static int	_in(char const c, char const *set)
{
	while (*set)
	{
		if (c == (char) *set)
			return (1);
		set++;
	}
	return (0);
}

// _calc_del(): calculate how many characters in the string will be
// 				removed after `ft_strtrim` has been preformed.
// return: the number of chars to be deleted.
static int	_calc_del(char const *s, char const *set)
{
	int	to_del;

	to_del = 0;
	while (*s)
	{
		if (_in((char) *s, set) == 1)
			to_del++;
		s++;
	}
	return (to_del);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	int		to_del;
	int		new_len;
	int		i;
	int		j;

	if (*s1 == '\0')
		return ((char *) s1);
	to_del = _calc_del(s1, set);
	new_len = ft_strlen((char *) s1) - to_del;
	new_s = (char *)malloc((new_len * sizeof(char)) + 1);
	if (new_s != NULL)
	{
		i = 0;
		j = 0;
		while (s1[i] != '\0')
		{
			if (_in(s1[i], set) == 0)
				new_s[j++] = s1[i];
			i++;
		}
		return (new_s);
	}
	return (NULL);
}
