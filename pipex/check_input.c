/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:40:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/13 13:29:26 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./ft_printf/includes/ft_printf.h"
#include "./pipex.h"

int	print_error(char *message, int code)
{
	ft_printf(B_RED WHITE " <   "S_BOLD S_UNDERLINE "Error!" R B_RED WHITE
		" %s   > " R "\n" R, message);
	return (code);
}

int	check_input(int argc, char **argv)
{
	if (argc < 5 || argc > 5)
	{
		print_error("Wrong input!", 1);
		print_usage();
		return (1);
	}
	if (access(argv[1], F_OK) != 0)
		return (print_error("Can't access \'INFILE\'.", 2));
	return (0);
}
