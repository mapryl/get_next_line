/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:46:47 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/04 17:30:48 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_str;
	size_t	little_len;
	size_t	j;
	size_t	i;

	big_str = (char*)big;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return (big_str);
	if (ft_strlen(big) < little_len || len < little_len)
		return (NULL);
	i = 0;
	while (big_str[i] && i <= len - little_len)
	{
		j = 0;
		while (little[j] && little[j] == big_str[i + j])
			j++;
		if (j == little_len)
			return (&big_str[i]);
		i++;
	}
	return (NULL);
}
