/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:59:30 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/16 15:26:48 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int	test_calloc(size_t nmemb, size_t size)
{
	void	*ft_array;
	void	*array;
	size_t	i;

	printf("- - - -\n");
	array = NULL;
	ft_array = NULL;
	if (size == 4)
	{
		printf("int");
		ft_array = (int *)ft_calloc(nmemb, size);
		array = (int *)calloc(nmemb, size);
	}
	else if (size == 1)
	{
		printf("char");
		ft_array = (char *)ft_calloc(nmemb, size);
		array = (char *)calloc(nmemb, size);
	}
	else if (size == 2)
	{
		printf("short");
		ft_array = (short *)ft_calloc(nmemb, size);
		array = (short *)calloc(nmemb, size);
	}
	else if (size == 8)
	{
		printf("lli");
		ft_array = (long long int *)ft_calloc(nmemb, size);
		array = (long long int *)calloc(nmemb, size);
	}
	if (ft_array != NULL && array != NULL)
	{
		printf("\nft[ptr]=%p | std(ptr)=%p\nnmemb=%lu\nsize=%lu\n", &ft_array, &array, nmemb, size);
		i = 0;
		while (i < nmemb)
		{
			printf("ft[sizeof=%lu, pointer=%p] | std(sizeof=%lu, pointer=%p)\n",
				sizeof(ft_array[i]), &ft_array[i], sizeof(array[i]), &array[i]);
			i++;
		}
	}
	else
	{
		printf("ft[ptr]=%p | std(ptr)=%p\nnmemb=%lu\nsize=%lu\n", &ft_array, &array, nmemb, size);
		if (ft_array == NULL)
			printf("[FT] NULL.\n");
		if (array == NULL)
			printf("[STD] NULL.\n");
	}
	free(ft_array);
	free(array);

	return (0);
}
