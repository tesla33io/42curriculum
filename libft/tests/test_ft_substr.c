/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:04:45 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/16 19:00:12 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int	test_ft_substr(char const *s, unsigned int start, \
	size_t len, char *expected)
{
	char	*result;
	int		ft_len;
	int		expect_len;

	g_num_test++;
	result = ft_substr(s, start, len);
	ft_len = ft_strlen(result);
	expect_len = ft_strlen(expected);
	printf("[%d] result = [ %s ]\n", ft_len, result);
	printf("[%d] expected = [ %s ]\n", expect_len, expected);
	if ((ft_memcmp(result, expected, (size_t) ft_len) == 0) \
		&& (ft_len == expect_len))
	{
		free(result);
		print_ok();
		return (0);
	}
	free(result);
	print_ko();
	return (1);
}
