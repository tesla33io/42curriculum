/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:16:20 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/26 15:55:55 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void free_list(t_list *head)
{
	if (head)
		free_list((t_list *)head->next);
	free(head);
}


int	test_ft_lstadd_front()
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node0;
	t_list	*lst;

	g_num_test++;
	lst = NULL;
	node1 = ft_lstnew("Node n1");
	node2 = ft_lstnew("Node n2");
	node3 = ft_lstnew("Node n3");
	node0 = ft_lstnew("Node n0");
	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node3);
	ft_lstadd_front(&lst, node0);
	t_list *temp = lst;
	if (temp && !strcmp((char *)temp->content, "Node n0")) {
		temp = temp->next;
		if (temp && !strcmp((char *)temp->content, "Node n3")) {
			temp = temp->next;
			if (temp && !strcmp((char *)temp->content, "Node n2")) {
				temp = temp->next;
				if (temp && !strcmp((char *)temp->content, "Node n1") \
					&& temp->next == NULL) {
					free_list(lst);
					print_ok();
					return (0);
				}
			}
		}
	}
	free_list(lst);
	print_ko();
	return (1);
}
