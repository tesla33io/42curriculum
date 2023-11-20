/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:45:50 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/16 17:47:01 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	test_strdup(const char *s)
{
	char	*result;
	char	*std_result;
	int		len;
	int		std_len;

	g_num_test++;
	result = ft_strdup(s);
	std_result = strdup(s);
	len = ft_strlen(result);
	std_len = ft_strlen(std_result);
	printf("result = [ %s ]\nlen = %d\n", result, len);
	printf("std_result = [ %s ]\nstd_len = %d\n", std_result, std_len);
	if ((ft_memcmp(result, std_result, std_len) == 0) && (len == std_len))
	{
		free(result);
		free(std_result);
		print_ok();
		return (0);
	}
	free(result);
	free(std_result);
	print_ko();
	return (1);
}
