/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:17:23 by likong            #+#    #+#             */
/*   Updated: 2024/05/28 14:29:59 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_zero(t_flags *fg, char *buff, int *buf_index)
{
	while (fg->zero == 1 && fg->minus == 0 && fg->dot == 0
		&& fg->len > fg->tlen && fg->neg == 0)
	{
		if (fg->add == 1)
		{
			check_buffer(buff, buf_index, '+', fg);
			fg->tlen--;
			fg->add = 0;
		}
		check_buffer(buff, buf_index, '0', fg);
	}
	return (1);
}

static int	check_dot(t_flags *fg, long num, char *buff, int *buf_index)
{
	if (check_zero(fg, buff, buf_index) == -1)
		return (-1);
	if (fg->add == 1)
	{
		check_buffer(buff, buf_index, '+', fg);
		fg->tlen--;
	}
	while (fg->perc > fg->slen++ || (fg->len > fg->tlen && fg->dot == 0
			&& fg->minus == 0 && fg->nul != 1))
		check_buffer(buff, buf_index, '0', fg);
	fg->base = DECIMEL;
	if (print_base_h(num, fg, &buff, buf_index) == -1)
		return (-1);
	fg->tlen -= get_number_size((unsigned long long)num, 10);
	while (fg->minus == 1 && fg->len > fg->tlen)
		check_buffer(buff, buf_index, ' ', fg);
	return (1);
}

static int	check_width(t_flags *fg, long num, char *buff, int *buf_index)
{
	if (fg->len > fg->tlen && fg->minus == 0)
	{
		while ((fg->tlen + fg->mlen + fg->neg - fg->nul < fg->len
				&& fg->zero == 0
				&& fg->perc + fg->mlen + fg->neg + fg->add + fg->space
				< fg->len) || (fg->zero == 1 && fg->dot == 1
				&& fg->len > (fg->perc + fg->mlen + fg->neg + fg->space
					+ fg->add)
				&& fg->len > (fg->tlen + fg->neg + fg->mlen - fg->nul)))
		{
			check_buffer(buff, buf_index, ' ', fg);
			fg->tlen--;
			fg->mlen++;
		}
		fg->tlen += fg->mlen;
	}
	if (fg->neg == 1)
		check_buffer(buff, buf_index, '-', fg);
	if (check_dot(fg, num, buff, buf_index) == -1)
		return (-1);
	return (1);
}

static int	check_add_space(t_flags *fg, long num, char *buff, int *buf_index)
{
	if (fg->space != 0 && fg->add == 0 && fg->neg == 0)
		check_buffer(buff, buf_index, ' ', fg);
	else if (fg->add != 0 && fg->neg == 1)
		fg->add = 0;
	else if (fg->add != 0)
		fg->tlen++;
	if (fg->neg == 1)
		fg->space = 0;
	if (check_width(fg, num, buff, buf_index) == -1)
		return (-1);
	return (1);
}

int	ft_putnbr_bonus(int n, t_flags *fg)
{
	long	num;
	char	buff[4096];
	int		buf_index;

	num = n;
	buf_index = 0;
	if (num < 0)
	{
		fg->neg = 1;
		num = -num;
	}
	if (num == 0)
		fg->nul = 1;
	if (num == 0 && fg->zero == 0 && fg->dot == 0)
		fg->nul = 0;
	fg->slen = get_number_size((unsigned long long)num, 10);
	fg->tlen = get_number_size((unsigned long long)num, 10);
	if (check_add_space(fg, num, buff, &buf_index) == -1)
		return (-1);
	if (write(1, buff, buf_index) == -1)
		return (-1);
	return (fg->tlen);
}
