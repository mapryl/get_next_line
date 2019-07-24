/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 20:19:03 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/04 17:16:55 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int minus;

	minus = 0;
	if (n < 0)
	{
		ft_putchar('-');
		minus = 1;
	}
	if (n == -2147483648)
	{
		ft_putchar('2');
		n %= 1000000000;
		minus = 1;
	}
	if (minus == 1)
		n = -n;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}
