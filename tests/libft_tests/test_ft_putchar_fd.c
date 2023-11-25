/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:57:14 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/25 17:13:20 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	test_ft_putchar_fd(char c, int fd)
{
	printf("fd[%d]\nres = ", fd);
	ft_putchar_fd(c, fd);
	printf("\nexp = %c\n", c);
	return (0);
}