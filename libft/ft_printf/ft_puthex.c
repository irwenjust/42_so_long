/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:14:42 by likong            #+#    #+#             */
/*   Updated: 2024/05/23 10:47:51 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(int num, char *str)
{
	int				i;
	unsigned int	n;
	unsigned int	hex_len;

	i = 0;
	n = (unsigned int)num;
	hex_len = str_length(str);
	if (n >= hex_len)
	{
		i = ft_puthex(n / hex_len, str);
		if (i == -1)
			return (-1);
		if (write(1, &str[n % hex_len], 1) == -1)
			return (-1);
		i++;
	}
	else
	{
		if (write(1, &str[n], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}
