/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:39:00 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/04 17:04:24 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *node_to_apply;

	node_to_apply = lst;
	while (node_to_apply != NULL)
	{
		f(node_to_apply);
		node_to_apply = node_to_apply->next;
	}
}
