/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:39:19 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/17 21:38:11 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *src_node;
	t_list *prev_new_node;
	t_list *new_lst_head;
	t_list *new_node;

	src_node = lst;
	prev_new_node = NULL;
	new_lst_head = NULL;
	while (src_node != NULL)
	{
		new_node = f(src_node);
		if (new_node == NULL)
			return (new_lst_head);
		if (new_lst_head == NULL)
			new_lst_head = new_node;
		else
			prev_new_node->next = new_node;
		src_node = src_node->next;
		prev_new_node = new_node;
	}
	return (new_lst_head);
}
