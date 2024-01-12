/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:30:34 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/12 19:04:44 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "./pipex.h"

int	main(int argc, char **argv)
{
	t_data		*data;

	data = NULL;
	if (check_input(argc, argv) != 0)
		return (-1);
	if (parse_data(argc, argv, data) != 0)
		return (-1);
	if (data)
		free(data);
	return (0);
}
