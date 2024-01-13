/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:22:43 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/13 12:28:54 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "./ft_printf/includes/ft_printf.h"
#include "./pipex.h"

int	parse_data(int argc, char **argv, t_data *data)
{
	(void)argc;
	(void)argv;
	data = (t_data *) malloc(1 * sizeof(t_data));
	if (!data)
		return (print_error("Memory allocation failed during parsing.", 5));
	return (0);
}
