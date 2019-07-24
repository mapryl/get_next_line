/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:42:02 by mapryl            #+#    #+#             */
/*   Updated: 2019/04/29 10:42:02 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int minus;

	minus = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		minus = 1;
	}
	if (n == -2147483648)
	{
		ft_putchar_fd('2', fd);
		n %= 1000000000;
		minus = 1;
	}
	if (minus == 1)
		n = -n;
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
