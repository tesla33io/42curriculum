/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:30:36 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/07 13:05:21 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h> // <<<<< DELETE THIS !!!


int	process_uint(unsigned int arg, int fd)
{
	printf("pf u=%u | ftpf u =", arg);
	ft_putnbr_fd(arg, fd);
	ft_putchar_fd('\n', fd);
	return (0);
}

int	process_formatter(const char **s, va_list arg, int fd)
{
	int	count;

	count = 0;
	if (*(*s))
	{
		(*s)++;
		if (*(*s) == 'i' || *(*s) == 'd')
			count += formatter_di((int) va_arg(arg, int), count, fd);
		else if (*(*s) == 'u')
			count += formatter_u((unsigned int) va_arg(arg, unsigned int), count, fd);
		else if (*(*s) == 'c')
			count += formatter_c((char) va_arg(arg, int), count, fd);
		else if (*(*s) == 's')
			count += formatter_s((char *) va_arg(arg, char *), count, fd);
		else if (*(*s) == 'p')
			ft_putstr_fd(va_arg(arg, void *), fd);
		else if (*(*s) == 'x')
			count += formatter_x((unsigned int) va_arg(arg, unsigned int), count, fd);
		(*s)++;
	}
	return (count);
}

int	print(int fd, const char *s, va_list arg)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s != '%' && *s)
		{
			ft_putchar_fd(*s, fd);
			s++;
			count++;
		}
		count += process_formatter(&s, arg, fd);
	}
	return (1);
}
