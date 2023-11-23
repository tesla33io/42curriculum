/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:52:00 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/23 16:54:19 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	test_ft_split(const char *s, const char c, const char **exp)
{
	const char	**ft_result;
	int			i;
	int			error;

	g_num_test++;
	ft_result = (const char **) ft_split(s, c);
	if (!ft_result)
	{
		printf("Error allocating the memory (test_ft_split.c)\n");
		return (1);
	}
	printf("orig = |%s|\n", s);
	i = 0;
	error = 0;
	while (ft_result[i] != NULL)
	{
		if (ft_result && ft_result[i] && exp && exp[i])
			printf("w%d = |%s|\ne%d = |%s|\n--\n", i, ft_result[i], i, exp[i]);
		else
			printf("w%d = (null)\ne%d = |%s|\n--\n", i, i, exp[i]);
		error += ft_result[i] == exp[i];
		free((char *) ft_result[i]);
		i++;
	}
	printf("w%d = (null)\ne%d = |%s|\n--\n", i, i, exp[i]);
	free(ft_result);
	if (error == 0)
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}
