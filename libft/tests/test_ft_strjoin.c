/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:32:46 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/17 17:52:34 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int	test_ft_strjoin(char const *s1, char const *s2, char const *expected)
{
	char	*result;
	int		diff;

	g_num_test++;
	result = ft_strjoin(s1, s2);
	diff = strncmp(result, expected, strlen(expected));
	printf("orig:\n\ta) [ %s ]\n\tb) [ %s ]\nresult = [ %s ]\ndiff = %d\n---\n", \
		s1, s2, result, diff);
	free(result);
	if (result != NULL)
	{
		if (diff == 0)
		{
			print_ok();
			return (0);
		}
	}
	print_ko();
	return (1);
}
