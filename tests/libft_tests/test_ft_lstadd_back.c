/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:34:32 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/26 17:44:39 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	test_ft_lstadd_back()
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node0;
	t_list	*lst;
	t_list	*temp;

	g_num_test++;
	lst = NULL;
	node1 = ft_lstnew("n1");
	node2 = ft_lstnew("n2");
	node3 = ft_lstnew("n3");
	node0 = ft_lstnew("n0");
	ft_lstadd_front(&lst, node3);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node1);
	ft_lstadd_back(&lst, node0);
	temp = lst;
	if (temp && !strcmp((char *)temp->content, "n1")) {
		temp = temp->next;
		if (temp && !strcmp((char *)temp->content, "n2")) {
			temp = temp->next;
			if (temp && !strcmp((char *)temp->content, "n3")) {
				temp = temp->next;
				if (temp && !strcmp((char *)temp->content, "n0") \
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