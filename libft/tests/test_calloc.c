/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:59:30 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/13 19:06:45 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int	test_calloc(size_t nmemb, size_t size)
{
	char	*test;

	g_num_test++;
	test = (char *) ft_calloc(nmemb, size);
	printf("result=[ %s ]", test);
	free(test);
	return (0);
}