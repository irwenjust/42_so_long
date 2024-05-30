/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:27:57 by likong            #+#    #+#             */
/*   Updated: 2024/05/28 14:29:53 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	put_char(char c, t_flags *fg)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	fg->tlen++;
	return (1);
}

static int	check_char(t_flags *fg, char c, char *buff, int *index)
{
	if (fg->minus == 1)
	{
		check_buffer(buff, index, (char)c, fg);
		while (fg->tlen < fg->len)
			check_buffer(buff, index, ' ', fg);
	}
	else if (fg->len != 0 && fg->zero == 0)
	{
		while (fg->tlen < fg->len - 1)
			check_buffer(buff, index, ' ', fg);
		check_buffer(buff, index, (char)c, fg);
	}
	else if (fg->len != 0 && fg->zero != 0)
	{
		while (fg->tlen < fg->len - 1)
			check_buffer(buff, index, '0', fg);
		check_buffer(buff, index, (char)c, fg);
	}
	else
		check_buffer(buff, index, (char)c, fg);
	return (1);
}

int	ft_putchar_bonus(int c, t_flags *fg)
{
	char	buff[4096];
	int		index;

	index = 0;
	if (check_char(fg, c, buff, &index) == -1)
		return (-1);
	if (write(1, buff, index) == -1)
		return (-1);
	return (fg->tlen);
}
