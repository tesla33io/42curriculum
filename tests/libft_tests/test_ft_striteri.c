/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:07:37 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/24 22:17:43 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	test_ft_striteri(char *s, void (*f)(unsigned int, char *), char *exp)
{
	int	diff;

	g_num_test++;
	ft_striteri(s, f);
	diff = strcmp(s, exp);
	if (diff == 0)
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}
