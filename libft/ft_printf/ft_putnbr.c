/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:06:21 by likong            #+#    #+#             */
/*   Updated: 2024/05/28 14:27:40 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		len;
	long	num;

	num = n;
	len = 0;
	if (num < 0 && ++len)
	{
		num = -num;
		if (write(1, "-", 1) == -1)
			return (-1);
	}
	if (num >= 10)
	{
		len += ft_putnbr((int)(num / 10));
		if (len == -1)
			return (-1);
		num = num % 10;
	}
	if (num <= 9)
	{
		if (ft_putchar(('0' + num)) == -1)
			return (-1);
		len++;
	}
	return (len);
}
