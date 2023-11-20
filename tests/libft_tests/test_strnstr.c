/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:48:25 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/13 18:37:14 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

int	test_strnstr(char *big, char *little, size_t len)
{
	char	*ft_result;
	char	*result;

	g_num_test++;
	ft_result = ft_strnstr(big, little, len);
	result = strnstr(big, little, len);
	printf("ft_strnstr=[ %s ]\nstrnstr=[ %s ]\n", ft_result, result);
	if (ft_result == result)
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}