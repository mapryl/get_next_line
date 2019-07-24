/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:45:58 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/16 20:32:04 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long		result;
	unsigned long			i;
	int						sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = (unsigned long long)(result * 10) + (str[i] - '0');
		if (result > (long long)FT_MAX_ATOI && sign == 1)
			return (-1);
		if (result > (long long)FT_MAX_ATOI && sign == -1)
			return (0);
		i++;
	}
	return ((int)result * sign);
}
