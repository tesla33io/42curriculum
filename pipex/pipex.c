/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:30:34 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/17 18:14:23 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "./pipex.h"

// void	exec(t_pipex **data, char **env)
// {
// 	int	i;

// 	dup2((*data)->in_fd, STDIN_FILENO);
// 	dup2((*data)->out_fd, STDOUT_FILENO);
// 	i = 0;
// 	while (i < (*data)->cmd_count)
// 	{
// 		execve((*data)->cmd_paths[i], ft_split(), env);
// 		i++;
// 	}
// }

int	main(int argc, char **argv, char **env)
{
	t_pipex		*data;
	int			i;

	i = 0;
	data = init_pipex(env);
	if (check_input(argc, argv) != 0)
		exit (EXIT_FAILURE);
	if (parse_data(argc, argv, &data) != 0)
		end(&data);
	exec(&data, env);
	end(&data);
	return (0);
}
