/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:33:36 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/13 13:10:44 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"
#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*new_s;
	int		s_len;
	int		i;

	s_len = ft_strlen((char *) s) + 1;
	new_s = (char *)malloc(s_len * sizeof(char));
	if (new_s != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			new_s[i] = s[i];
			i++;
		}
		new_s[i] = '\0';
		return (new_s);
	}
	return (NULL);
}
