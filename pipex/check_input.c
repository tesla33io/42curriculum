/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:40:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/06 20:37:12 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./pipex.h"

int	print_error(char *msg, char *msg2, char *msg3, int code)
{
	ft_printf(STDERR_FILENO, RED S_BOLD "[!] Error: " R
		RED "%s%s%s" R "\n" R, msg, msg2, msg3);
	return (code);
}

int	check_input(int argc, char **argv)
{
	if (argc < 5)
	{
		print_error("Wrong input!", "", "", -1);
		print_usage();
		return (1);
	}
	if (access(argv[1], F_OK) != 0)
	{
		return (print_error("File \'", argv[1],
				"\' does not exist (INFILE).", -1));
	}
	if (access(argv[1], R_OK) != 0)
		return (print_error("Can't read '", argv[1], "' (INFILE).", -1));
	return (0);
}
