/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:59:36 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/26 18:02:46 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	test_ft_lstdelone()
{
	t_list	*node;

	node = ft_lstnew(malloc(1));
	ft_lstdelone(node, free);
	node = NULL;
	return (0);
}