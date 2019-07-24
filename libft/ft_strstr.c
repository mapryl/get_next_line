/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:35:16 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/04 18:27:58 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;
	size_t j;

	if (!ft_strlen(little))
		return ((char*)big);
	i = 0;
	while (big[i])
	{
		if (big[i] == little[0])
		{
			j = 1;
			while (little[j] && big[i + j] == little[j])
				j++;
			if (little[j] == '\0')
				return ((char*)&big[i]);
		}
		i++;
	}
	return (0);
}
