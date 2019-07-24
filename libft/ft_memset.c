/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:52:18 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/04 17:16:02 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;
	unsigned char symb;

	ptr = (unsigned char *)b;
	symb = (unsigned char)c;
	while (len--)
	{
		*(ptr++) = symb;
	}
	return (b);
}
