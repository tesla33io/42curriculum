/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:30:36 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/05 17:15:34 by astavrop         ###   ########.fr       */
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


int	print(int fd, const char *s, va_list arg)
{
	while (*s)
	{
		while (*s != '%' && *s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
		if (*s)
		{
			s++;
			printf("\n\t%c - c\n", *s);
			if (*s == 'i')
				ft_putnbr_fd(va_arg(arg, int), fd);
			else if (*s == 'd')
				ft_putnbr_fd(va_arg(arg, double), fd);
			else if (*s == 'u')
				process_uint(va_arg(arg, unsigned int), fd);
			else if (*s == 'c')
				ft_putchar_fd(va_arg(arg, int), fd);
			else if (*s == 's')
				ft_putstr_fd(va_arg(arg, char *), fd);
			else if (*s == 'p')
				ft_putstr_fd(va_arg(arg, void *), fd);
			s++;
		}
	}
	return (1);
}
