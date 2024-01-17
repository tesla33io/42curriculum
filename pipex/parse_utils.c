/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:19:50 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/17 17:39:35 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./pipex.h"

char	*get_bin(char *cmd)
{
	char	*bin;
	char	**cmdv;

	cmdv = ft_split(cmd, ' ');
	if (!cmdv)
		return (NULL);
	bin = ft_strdup(cmdv[0]);
	list_free(cmdv);
	return (bin);
}
