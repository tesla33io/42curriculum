/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:22:43 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/15 20:09:15 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./pipex.h"

int	parse_fd(int argc, char **argv, t_pipex **data)
{
	(*data)->in_fd = open(argv[1], O_RDONLY);
	if ((*data)->in_fd < 0)
		return (print_error("Can't open \'INFILE\'", "", "", -1));
	(*data)->out_fd = open(argv[argc - 1], O_WRONLY);
	if ((*data)->out_fd < 0)
	{
		(*data)->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT, 00777);
		if ((*data)->out_fd < 0)
			return (print_error("Can't open \'OUTFILE\'", "", "", -1));
	}
	return (0);
}

char	*check_cmd(char *cmd, char **paths)
{
	char	*path;
	char	*bin;

	bin = ft_split(cmd, ' ')[0];
	if (!bin)
		return (NULL);
	if ((ft_strncmp(bin, "./", 2) == 0) \
		&& access(bin, X_OK) == 0)
		return (ft_strdup(bin));
	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		path = ft_strjoin(path, bin);
		if (access(path, X_OK) == 0)
		{
			free(bin);
			return (path);
		}
		paths++;
	}
	print_error("Command \'", bin, "\' not found.", -1);
	free(bin);
	return (NULL);
}

int	parse_cmds(int argc, char **argv, t_pipex **data)
{
	int		i;
	char	*cmd;
	char	*cmds;

	cmd = NULL;
	cmds = (char *) malloc(1 * sizeof(char));
	if (!cmds)
		return (-1);
	i = 2;
	while (i < argc - 1)
	{
		cmd = check_cmd(argv[i], (*data)->path);
		if (!cmd)
			return (-1);
		cmd = ft_strjoin(cmd, ":");
		cmds = ft_strjoin(cmds, cmd);
		free(cmd);
		i++;
	}
	(*data)->cmd_paths = ft_split(cmds, ':');
	return (0);
}

int	parse_data(int argc, char **argv, t_pipex **data)
{
	int	i;

	i = 0;
	(void)argc;
	(void)argv;
	if (parse_fd(argc, argv, &(*data)) != 0)
		return (-1);
	if (parse_cmds(argc, argv, &(*data)) != 0)
		return (-1);
	while ((*data)->cmd_paths[i])
		ft_printf(1, "|%s|\n", (*data)->cmd_paths[i++]);
	return (0);
}
