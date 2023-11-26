/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:15:43 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/26 14:28:48 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	test_ft_lstnew()
{
	t_list	*node;

	g_num_test++;
	node = ft_lstnew("This is head of list.");
	if (node)
	{
		if ((strcmp(node->content, "This is head of list.") == 0) \
			&& (node->next == NULL))
		{
			free(node);
			print_ok();
			return (0);
		}
	}
	free(node);
	print_ko();
	return (1);
}