/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 20:23:11 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/04 16:58:01 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_len(int n)
{
	size_t			i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			length;
	unsigned int	number;

	length = str_len(n);
	number = n;
	if (n < 0)
	{
		number = -n;
		length++;
	}
	str = ft_strnew(length);
	if (!str)
		return (NULL);
	str[length] = '\0';
	length--;
	str[length--] = number % 10 + '0';
	while (number /= 10)
		str[length--] = number % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
