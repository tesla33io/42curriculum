/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:01:22 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/17 19:40:24 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int	test_ft_strtrim(char const *s1, char const *set, char const *expected)
{
	char	*result;
	int		diff;

	g_num_test++;
	result = ft_strtrim(s1, set);
	if (result == NULL)
	{
		printf("ERROR: memory allocation failed (test_ft_strtrim.c)\n");
		free(result);
		return (1);
	}
	diff = strncmp(result, expected, strlen(expected));
	if (result[0] != '\0')
		printf("-------\nresult = [ %s ]\n", result);
	else
		printf("-------\nresult = empty\n");
	printf("orig: [ %s ]\nset = [ %s ]\n....\nexpected = \
[ %s ]\ndiff = %d\n", s1, set, expected, diff);
	free(result);
	if (diff == 0)
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}
