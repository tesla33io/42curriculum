/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:15:18 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/07 12:22:51 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int	ft_puthex_fd(unsigned int num, int fd)
{
	int	length;
	int	remainder;

	if (num == 0)
	{
		ft_putchar_fd('0', fd);
		return (1); // Hex length of 0 is 1
	}
	length = 0;
	if (num != 0)
	{
		length = ft_puthex_fd(num / 16, fd);
		remainder = num % 16;
		if (remainder < 10)
			ft_putchar_fd(remainder + '0', fd);
		else
			ft_putchar_fd(remainder - 10 + 'A', fd);
		length++;
	}
	return (length);
}

int	formatter_x(unsigned int x, int count, int fd)
{
	return (count + ft_puthex_fd(x, fd));
}

// int	formatter_X(unsigned int x, int count, int fd)
// {
// 	return (count + ft_strlen(s));
// }
