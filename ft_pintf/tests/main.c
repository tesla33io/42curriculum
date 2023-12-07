/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:44:03 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/07 13:16:44 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

int	main(void)
{
	int		fd;

	fd = 1;
	ft_putstr_fd("\n\nStart printf tests...\n><\n><\n", fd);
	ft_printf("uint %u\n", UINT_MAX);
	ft_printf("min int i %i\n", INT_MIN);
	ft_printf("min int d %d\n", INT_MIN);
	ft_printf("max int i %i\n", INT_MAX);
	ft_printf("max int d %d\n", INT_MAX);
	ft_printf("char %c\n", 'C');
	ft_printf("char %c\n", 'c');
	ft_printf("char (int) %c\n", 65);
	ft_printf("char (int) %c\n", 65 + 32);
	ft_printf("string <%s>\n", "This is string");
	ft_printf("hex %x\n", 4779);
	ft_printf("String #%u with c %c\n", 123, 'A');
	ft_printf("%s in string\n", "Anothre string,\t");
	return (0);
}
