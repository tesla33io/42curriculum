/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:36:06 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/26 20:11:09 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void free_str_ptr(void *str)
{
	printf("del [%s]\n", (char *) str);
	free((void *) str);
}

int	test_ft_lstclear()
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
	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node3);
	ft_lstadd_front(&lst, node0);
	printf("n1 ptr (%p)\n", node1->next);
	ft_lstclear(&lst + 2, free_str_ptr);
	temp = lst;
	if (temp && !strcmp((char *)temp->content, "n0")) {
		temp = temp->next;
		printf("next->%s ", (unsigned char *) temp->next);
		printf("ptr(%p)\n", temp->next->next);
		if (temp && !strcmp((char *)temp->content, "n3") \
			&& temp->next == NULL) {
			free_list(lst);
			print_ok();
			return (0);
		}
	}
	free_list(lst);
	print_ko();
	return (1);
}