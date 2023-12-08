/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:44:03 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/08 10:51:21 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

int	main(void)
{
	int		fd;

	fd = 1;
	ft_putstr_fd("\n\nStart printf tests...\n\n\n", fd);
	ft_printf("uint %u\n", UINT_MAX);
	ft_printf("min int d %d\n", INT_MIN);
	ft_printf("max int d %d\n", INT_MAX);
	ft_printf("int %d\n", 0);
	ft_printf("char %c\n", 'C');
	ft_printf(" %c ", '0');
	ft_printf("char (int) %c\n", 65);
	ft_printf("string <%s>\n", "This is string");
	ft_printf("hex %x\n", 4779);
	ft_printf("hex %x\n", -4779);
	ft_printf("hex %x\n", 0);
	ft_printf("hex (lm) %x\n", LONG_MIN);
	ft_printf("ptr %p\n", -1);
	ft_printf("other %%\n");
	ft_printf("other %a\n");
	ft_printf("other %k\n");
	ft_putstr_fd("\n\nEnd of the tests.\n", fd);
	return (0);
}
