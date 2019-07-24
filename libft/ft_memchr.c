/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:42:43 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/04 17:12:12 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	symb;

	str = (unsigned char *)s;
	symb = (unsigned char)c;
	while (n--)
	{
		if (*str == symb)
			return (str);
		str++;
	}
	return (NULL);
}
