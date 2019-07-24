/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:38:27 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/04 17:01:27 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node_to_del;
	t_list	*next;

	node_to_del = *alst;
	while (node_to_del != NULL)
	{
		next = node_to_del->next;
		ft_lstdelone(&node_to_del, del);
		node_to_del = next;
	}
	*alst = NULL;
}
