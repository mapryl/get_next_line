/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:39:36 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/04 20:14:01 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_dup(void const *mem, size_t size)
{
	void		*result;
	const char	*src;
	char		*dst;
	size_t		i;

	if (!mem || !size)
		return (NULL);
	result = malloc(size);
	if (!result)
		return (NULL);
	i = 0;
	src = (const char *)mem;
	dst = (char *)result;
	while (i < size)
	{
		*dst++ = *src++;
		i++;
	}
	return (result);
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_node;

	new_node = (t_list*)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	if (!content)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
	}
	else
	{
		if ((new_node->content = ft_dup(content, content_size)) == NULL)
		{
			free(new_node);
			return (NULL);
		}
		new_node->content_size = content_size;
	}
	return (new_node);
}
