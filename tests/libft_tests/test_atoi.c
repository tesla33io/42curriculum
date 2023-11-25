/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:28:18 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/25 17:40:57 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	test_atoi(const char *nptr, int exp)
{
	int	result;

	g_num_test++;
	result = ft_atoi(nptr);
	printf("%d | %d\n", result, exp);
	if (result == exp)
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}