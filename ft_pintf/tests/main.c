/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:44:03 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/05 17:16:01 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

int	main(void)
{
	int		fd;

	fd = 1;
	ft_putstr_fd("\n\nStart printf tests...\n><\n><\n", fd);
	ft_printf("This %u is i test i string\n", UINT_MAX, INT_MAX, INT_MIN);
	// ft_printf("String #%u with c %c\n", 123, 'A');
	// ft_printf("%s in string", "Anothre string,");
	return (0);
}
// UINT_MAX	4294967295 (0xffffffff)
