/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:15:18 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/07 12:53:37 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int	numlen(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	formatter_di(int n, int count, int fd)
{
	ft_putnbr_fd(n, fd);
	return (count + numlen((long int) n));
}
