/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:36:52 by likong            #+#    #+#             */
/*   Updated: 2024/05/28 14:30:03 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	put_str(char *str, t_flags *fg, char *buff, int *index)
{
	int	i;

	i = 0;
	while (str[i] && i < fg->slen)
	{
		check_buffer(buff, index, str[i], fg);
		i++;
	}
	return (i);
}

static int	check_string(char *str, t_flags *fg, char *buff, int *index)
{
	if (fg->minus == 1)
	{
		if (fg->perc >= fg->slen || fg->perc == 0)
		{
			if (put_str(str, fg, buff, index) == -1)
				return (-1);
		}
		while (fg->tlen < fg->len)
			check_buffer(buff, index, ' ', fg);
	}
	else if (fg->len > fg->slen)
	{
		if (fg->zero == 1)
			while (fg->tlen < fg->len - fg->slen)
				check_buffer(buff, index, '0', fg);
		else
			while (fg->tlen < fg->len - fg->slen)
				check_buffer(buff, index, ' ', fg);
		if (put_str(str, fg, buff, index) == -1)
			return (-1);
	}
	else
		if (put_str(str, fg, buff, index) == -1)
			return (-1);
	return (fg->tlen);
}

int	ft_putstr_bonus(char *str, t_flags *fg)
{
	int		len;
	int		slen;
	char	buff[4096];
	int		index;

	len = 0;
	slen = 0;
	index = 0;
	if (!str)
	{
		str = "(null)";
		fg->slen = 6;
		fg->nul = 1;
	}
	if (fg->perc <= (int)str_length(str) && fg->dot == 1)
		fg->slen = fg->perc;
	else
		fg->slen = str_length(str);
	if (check_string(str, fg, buff, &index) == -1)
		return (-1);
	if (write(1, buff, index) == -1)
		return (-1);
	return (fg->tlen);
}
