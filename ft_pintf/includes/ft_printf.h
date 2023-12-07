/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:23:06 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/07 12:59:21 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

// General
int			ft_printf(const char *s, ...);
int			print(int fd, const char *s, va_list arg);

// Formaters
int			formatter_c(char c, int count, int fd);
int			formatter_s(char *s, int count, int fd);
int			formatter_di(int n, int count, int fd);
int			formatter_u(unsigned int n, int count, int fd);
int			formatter_x(unsigned int x, int count, int fd);

// Additional
int			numlen(long int n);

#endif // !FT_PRINTF_H
