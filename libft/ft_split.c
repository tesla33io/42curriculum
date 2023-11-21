/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:40:44 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/21 20:22:07 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	count_words(char const *s, char c)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			words++;
			in_word = 1;
		}
		s++;
	}
	return (words);
}

static int	count_letters(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**r_array;
	int		len;
	int		words;
	int		i;
	int		j;

	words = count_words(s, c);
	r_array = (char **) malloc((words + 1) * sizeof(char *));
	if (!r_array)
		return (NULL);
	i = 0;
	while (i < words)
	{
		j = 0;
		while (*s == c)
			s++;
		len = count_letters(s, c);
		r_array[i] = (char *) malloc((len + 1) * sizeof(char));
		while (*s != c)
		{
			r_array[i][j] = *s;
			j++;
			s++;
		}
		i++;
	}
	r_array[i] = NULL;
	return (r_array);
}
