/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:15:18 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/07 18:41:16 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int	ft_puthex_fd(long int num, int fd)
{
	char		hex_digit;
	int			remainder;
	int			temp;
	static int	len;

	if (num == 0)
	{
		temp = len;
		len = 0;
		return (temp);
	}
	ft_puthex_fd(num / 16, fd);
	remainder = num % 16;
	if (remainder < 10)
		hex_digit = '0' + remainder;
	else
		hex_digit = 'a' + remainder - 10;
	ft_putchar_fd(hex_digit, fd);
	len++;
	return (len);
}

int	formatter_x(long int x, int count, int fd)
{
	if (x == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	return (count + ft_puthex_fd(x, fd));
}

// int	formatter_X(unsigned int x, int count, int fd)
// {
// 	return (count + ft_strlen(s));
// }
