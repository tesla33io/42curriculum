/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:04:45 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/17 17:29:33 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	test_ft_substr(char const *s, unsigned int start, \
	size_t len, char *expected)
{
	char	*result;
	int		ft_len;
	int		expect_len;
	int		diff;

	g_num_test++;
	result = ft_substr(s, start, len);
	if (result == NULL)
	{
		printf("Error allocating memeory (test_ft_substr.c)\n");
		return (1);
	}
	ft_len = strlen(result);
	expect_len = strlen(expected);
	diff = memcmp(result, expected, expect_len);
	printf("[%d] result = [ %s ]\n", ft_len, result);
	printf("[%d] expected = [ %s ]\n", expect_len, expected);
	printf("diff = %d\n", diff);
	free(result);
	if ((diff == 0) && (ft_len == expect_len))
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}
