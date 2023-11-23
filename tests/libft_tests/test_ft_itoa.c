/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:45:25 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/23 22:51:26 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	test_ft_itoa(int n, char *exp)
{
	char	*ft_res;
	int		diff;

	g_num_test++;
	ft_res = ft_itoa(n);
	diff = strcmp(ft_res, exp);
	printf("n = %d\nexp = %s\nres = %s\ndiff = %d\n", n, exp, ft_res, diff);
	free(ft_res);
	if (diff == 0)
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}