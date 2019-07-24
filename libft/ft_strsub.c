/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:47:26 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/04 17:34:49 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!s || start + len > ft_strlen(s))
		return (NULL);
	result = ft_strnew(len);
	if (!result)
		return (NULL);
	while (i < len)
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}
