/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:15:38 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/26 17:21:37 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	test_ft_lstlast()
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*end;

	g_num_test++;
	node1 = ft_lstnew((void *) 1);
	node2 = ft_lstnew((void *) 2);
	node3 = ft_lstnew((void *) 3);
	node1->next = node2;
	node2->next = node3;
	end = ft_lstlast(node1);
	if ((int *) end->content == (int *) node3->content)
	{
		free_list(node1);
		print_ok();
		return (0);
	}
	free_list(node1);
	print_ko();
	return (1);
}