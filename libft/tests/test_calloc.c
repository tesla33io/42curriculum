/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:59:30 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/14 15:15:13 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int	test_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	i;

	array = NULL;
	if (size == 4)
	{
		array = (int *)calloc(nmemb, size);
	}
	else if (size == 1)
	{
		array = (char *)calloc(nmemb, size);
	}
	if (array != NULL)
	{
		printf("pointer=%p\nnmemb=%lu\nsize=%lu\n", &array, nmemb, size);
		i = 0;
		while (i < nmemb)
		{
			printf("[sizeof=%lu, pointer=%p]\n",
				sizeof(array[i]), &array[i]);
			i++;
		}
		free(array);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}

	return (0);
}