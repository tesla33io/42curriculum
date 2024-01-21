/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:21:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/21 17:17:02 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./pipex.h"

void	print_usage(void)
{
	ft_printf(STDOUT_FILENO, "\nUsage:\t" GREEN "./pipex " BLUE 
		"<INFILE> {\"CMD 1\" \"CMD 2\" ... \"CMD n\"} <OUTFILE>" R "\n\n");
	ft_printf(STDOUT_FILENO, "\t" BLUE "<INFILE>" R
		"\t- Input file for the program.\n");
	ft_printf(STDOUT_FILENO, "\t" BLUE "<OUTFILE>" R
		"\t- Output file for the program.\n");
	ft_printf(STDOUT_FILENO, "\t" BLUE "<CMD 1>" R
		"\t\t- First command to be executed.\n");
	ft_printf(STDOUT_FILENO, "\t" BLUE "<CMD 2>" R
		"\t\t- Second command to be executed.\n\n");
}

t_pipex	*init_pipex(char **env)
{
	t_pipex	*data;

	data = (t_pipex *) malloc(1 * sizeof(t_pipex));
	data->in_fd = -1;
	data->out_fd = -1;
	data->is_invalid_infile = 0;
	data->path = get_path(env);
	data->cmd_paths = NULL;
	data->cmd_args = NULL;
	data->row_c = 0;
	data->cmd_count = 0;
	return (data);
}

char	**get_path(char **env)
{
	char	**paths;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH", 4) == 0)
			break ;
		env++;
	}
	paths = ft_split(*env + 5, ':');
	return (paths);
}

char	**append_to_list(char **list, char *str)
{
	int		i;
	int		j;
	char	**new_list;

	i = 0;
	while (list[i++])
		continue ;
	new_list = (char **) malloc((i + 1) * sizeof(char *));
	j = 0;
	while (list[j])
	{
		new_list[j] = list[j];
		j++;
	}
	new_list[j] = str;
	new_list[j + 1] = NULL;
	return (new_list);
}
