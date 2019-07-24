/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:42:32 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/04 17:10:36 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	symb;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	symb = (unsigned char)c;
	while (n--)
	{
		*d++ = *s++;
		if (*(d - 1) == symb)
			return (d);
	}
	return (NULL);
}
