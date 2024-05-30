/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:31:36 by likong            #+#    #+#             */
/*   Updated: 2024/05/28 14:29:27 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_flags	create_struct(void)
{
	t_flags	new;

	new.add = 0;
	new.hash = 0;
	new.minus = 0;
	new.space = 0;
	new.zero = 0;
	new.len = 0;
	new.slen = 0;
	new.perc = 0;
	new.mlen = 0;
	new.tlen = 0;
	new.dot = 0;
	new.neg = 0;
	new.nul = 0;
	new.base = 0;
	new.err = 0;
	return (new);
}

static void	count_flags(t_flags *flags, char *str, size_t *i)
{
	if (str[*i] == '+')
		flags->add = 1;
	else if (str[*i] == ' ')
		flags->space = 1;
	else if (str[*i] == '#')
		flags->hash = 2;
	else if (str[*i] == '-' && !ft_strchr(CONVERSIONS, str[(*i) + 1]))
		flags->minus = 1;
	else if (str[*i] == '0' && !ft_strchr(CONVERSIONS, str[(*i) + 1]))
		flags->zero = 1;
	i++;
}

static int	get_value(char *str, size_t *i, int *value, va_list elements)
{
	long	num;

	num = 0;
	if (str[*i] == '*')
		*value = va_arg(elements, int);
	else
	{
		while (str[*i] == '0' && !ft_strchr(CONVERSIONS, str[(*i) + 1]))
			(*i)++;
		num = ft_atoi(str + (int)*i);
		if (*value < 0 || num > 2147483646)
		{
			*i += count_num_len((int)num);
			return (-1);
		}
		if (num != 0)
			*i += count_num_len((int)num);
		*value = num;
	}
	return (1);
}

t_flags	check_flags(char *str, size_t *i, va_list elements)
{
	t_flags	fg;

	fg = create_struct();
	while (!ft_strchr(CONVERSIONS, str[++(*i)]))
	{
		if (ft_strchr("+ #-0", str[*i]))
			count_flags(&fg, str, i);
		else if ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '*')
			fg.err = get_value(str, i, &fg.len, elements);
		else if (str[*i] == '.')
		{
			(*i)++;
			fg.dot = 1;
			if (ft_strchr(MNUMBER, str[(*i)]))
				fg.err = get_value(str, i, &fg.perc, elements);
			else if (str[(*i)] == '-')
				fg.minus = 1;
			if (ft_strchr(CONVERSIONS, str[(*i)]))
				break ;
		}
	}
	return (fg);
}
