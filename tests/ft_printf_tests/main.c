/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:34:23 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/19 16:41:54 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	ft = 42;
	int	my;
	int	nmy;

	my = ft_printf("Hello!\n");
	nmy = printf("Hello!\n");
	printf("Results: %d %d\n", my, nmy);
	my = ft_printf("%d %i %u %x %X\n", INT_MAX, INT_MIN, UINT_MAX, \
		UINT_MAX, INT_MAX);
	nmy = printf("%d %i %u %x %X\n", INT_MAX, INT_MIN, UINT_MAX, \
		UINT_MAX, INT_MAX);
	printf("Results: %d %d\n", my, nmy);
	my = ft_printf("%p %p\n", NULL, &ft);
	nmy = printf("%p %p\n", NULL, &ft);
	printf("Results: %d %d\n", my, nmy);
	my = ft_printf("%c%s\n", '!', "Hello world!");
	nmy = printf("%c%s\n", '!', "Hello world!");
	printf("Results: %d %d\n", my, nmy);
	return (0);
}
