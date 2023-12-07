/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:45:26 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/07 17:02:01 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		done;

	va_start (arg, s);
	done = print(1, s, arg);
	va_end (arg);
	return (done);
}
