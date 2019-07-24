/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:45:40 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/04 17:38:48 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	if (!s || !f)
		return (NULL);
	result = ft_strnew(ft_strlen(s));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
