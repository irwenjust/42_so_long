/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:18:00 by likong            #+#    #+#             */
/*   Updated: 2024/05/28 13:45:56 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	check_type(char *str, size_t *i, va_list elements)
{
	t_flags	fg;

	fg = check_flags(str, i, elements);
	if (fg.err == -1)
		return (-1);
	if (str[*i] == 'c')
		return (ft_putchar_bonus(va_arg(elements, int), &fg));
	else if (str[*i] == 's')
		return (ft_putstr_bonus(va_arg(elements, char *), &fg));
	else if (str[*i] == 'p')
		return (ft_putpoint_bonus(va_arg(elements, void *), &fg));
	else if (str[*i] == 'd' || str[*i] == 'i')
		return (ft_putnbr_bonus(va_arg(elements, int), &fg));
	else if (str[*i] == 'u')
		return (ft_putunbr_bonus(va_arg(elements, unsigned int), &fg));
	else if (str[*i] == 'x')
		return (ft_puthex_bonus(va_arg(elements, unsigned int), HEXL, &fg));
	else if (str[*i] == 'X')
		return (ft_puthex_bonus(va_arg(elements, unsigned int), HEXH, &fg));
	else if (str[*i] == '%')
		return (ft_putchar_bonus('%', &fg));
	return (0);
}

static int	next_func(char *str, va_list elements, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (len);
			j = check_type(str, &i, elements);
			if (j == -1)
				return (-1);
			len += (size_t)j;
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
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	va_start(elements, str);
	len = next_func((char *)str, elements, len);
	va_end(elements);
	return (len);
}
