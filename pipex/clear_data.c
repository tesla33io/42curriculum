/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:55:10 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/22 18:37:44 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./pipex.h"

void	close_fds(t_pipex **data)
{
	if ((*data)->in_fd > 0)
		close((*data)->in_fd);
	if ((*data)->out_fd > 0)
		close((*data)->out_fd);
}

void	list_free(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
		free(lst[i++]);
	free(lst);
}

void	d_list_free(char ***d_lst)
{
	int	i;
	int	j;

	if (!d_lst)
		return ;
	i = 0;
	while (d_lst[i])
	{
		j = 0;
		while (d_lst[i][j])
		{
			free(d_lst[i][j]);
			j++;
		}
		free(d_lst[i]);
		i++;
	}
	free(d_lst);
}

void	end(t_pipex **data)
{
	close_fds(&(*data));
	if ((*data)->path)
		list_free((*data)->path);
	if ((*data)->cmd_paths)
		list_free((*data)->cmd_paths);
	d_list_free((*data)->cmd_args);
	free((*data));
	exit (-1);
}
