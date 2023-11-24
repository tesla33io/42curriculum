/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:36:12 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/24 21:40:06 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	test_ft_strmapi(char const *s, char (*f)(unsigned int, char), char *exp)
{
	char	*result;
	int		diff;

	g_num_test++;
	result = ft_strmapi(s, f);
	printf("---\norig = %s\nexp = %s\nres = %s\n", s, exp, result);
	diff = strcmp(result, exp);
	free(result);
	if (diff == 0)
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}
