/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:06:22 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/26 16:16:28 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	test_ft_lstsize()
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*node5;
	t_list	*node0;
	t_list	*lst;
	int		len;

	g_num_test++;
	lst = NULL;
	node1 = ft_lstnew("Node n1");
	node2 = ft_lstnew("Node n2");
	node3 = ft_lstnew("Node n3");
	node4 = ft_lstnew("Node n4");
	node5 = ft_lstnew("Node n5");
	node0 = ft_lstnew("Node n0");
	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node3);
	ft_lstadd_front(&lst, node0);
	len = ft_lstsize(lst);
	printf("%d. ", len);
	ft_lstadd_front(&lst, node4);
	ft_lstadd_front(&lst, node5);
	len = ft_lstsize(lst);
	printf("%d\n", len);
	free_list(lst);
	if (len == 6)
	{
		print_ok();
		return (0);
	}
	print_ko();
	return (1);
}