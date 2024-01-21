/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:30:34 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/22 19:22:58 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "./pipex.h"

void	ex_cmd(t_pipex **data, char **env)
{
	int	i;

	dup2((*data)->in_fd, STDIN_FILENO);
	dup2((*data)->out_fd, STDOUT_FILENO);
	i = 0;
	while (i < (*data)->cmd_count)
	{
		execve((*data)->cmd_paths[i], (*data)->cmd_args[i], env);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex		*data;
	int			i;

	i = 0;
	if (check_input(argc, argv) != 0)
		exit (EXIT_FAILURE);
	data = init_pipex(env);
	if (parse_data(argc, argv, &data) != 0)
		end(&data);
	if (parse_args(argc, argv, &data) != 0)
		end(&data);
	while (i < data->cmd_count)
	{
		ex_cmd(&data, env);
		i++;
	}
	end(&data);
	return (0);
}
