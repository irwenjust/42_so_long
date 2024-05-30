/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:31:12 by likong            #+#    #+#             */
/*   Updated: 2024/05/23 18:18:51 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(const char *str, size_t i, va_list elements)
{
	if (str[i] == 'c')
		return (ft_putchar(va_arg(elements, int)));
	else if (str[i] == 's')
		return (ft_putstr(va_arg(elements, char *)));
	else if (str[i] == 'p')
		return (ft_putpoint(va_arg(elements, void *)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr(va_arg(elements, int)));
	else if (str[i] == 'u')
		return (ft_putnum_unsign(va_arg(elements, unsigned int)));
	else if (str[i] == 'x')
		return (ft_puthex(va_arg(elements, int), HEXL));
	else if (str[i] == 'X')
		return (ft_puthex(va_arg(elements, int), HEXH));
	else if (str[i] == '%')
		return (write(1, "%", 1));
	return (0);
}

static int	next_func(const char *str, va_list elements, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (len);
			j = check_type(str, ++i, elements);
			if (j == -1)
				return (-1);
			len += j;
		}
		else
		{
			if (write(1, &str[i], 1) != 1)
				return (-1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	elements;
	int		len;

	len = 0;
	va_start(elements, str);
	len = next_func(str, elements, len);
	va_end(elements);
	return (len);
}
