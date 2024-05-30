/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:25:55 by likong            #+#    #+#             */
/*   Updated: 2024/05/28 14:29:55 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_hash(t_flags *fg, unsigned int unum, char *buff, int *index)
{
	if (fg->hash == 2 && fg->base == HEXL && unum > 0)
	{
		check_buffer(buff, index, '0', fg);
		check_buffer(buff, index, 'x', fg);
	}
	else if (fg->hash == 2 && fg->base == HEXH && unum > 0)
	{
		check_buffer(buff, index, '0', fg);
		check_buffer(buff, index, 'X', fg);
	}
	return (1);
}

static int	check_zero(unsigned int unum, t_flags *fg, char *buff, int *index)
{
	if (check_hash(fg, unum, buff, index) == -1)
		return (-1);
	if (fg->perc > fg->slen)
	{
		while (fg->slen + fg->mlen++ < fg->perc)
			check_buffer(buff, index, '0', fg);
	}
	else if (fg->zero > 0 && fg->len > fg->slen
		&& fg->perc == 0 && fg->hash == 0)
	{
		while (fg->len > fg->slen + fg->mlen++)
			check_buffer(buff, index, '0', fg);
	}
	else if (fg->zero > 0 && fg->len > fg->slen + 2
		&& fg->perc == 0)
	{
		while (fg->len > fg->slen + 2 + fg->mlen++)
			check_buffer(buff, index, '0', fg);
	}
	if (print_base_h(unum, fg, &buff, index) == -1)
		return (-1);
	return (1);
}

static int	check_front(unsigned int unum, t_flags *fg, char *buff, int *index)
{
	if (fg->hash == 2 && unum == 0)
		fg->hash = 0;
	if (fg->len > 0 && fg->dot == 1)
	{
		while (fg->len > fg->perc + fg->tlen + fg->hash
			&& fg->len > fg->slen + fg->tlen + fg->hash)
			check_buffer(buff, index, ' ', fg);
	}
	else if (fg->len > 0 && fg->dot == 0 && fg->zero == 0)
	{
		while (fg->len > fg->slen + fg->tlen + fg->hash)
			check_buffer(buff, index, ' ', fg);
	}
	if (check_zero(unum, fg, buff, index) == -1)
		return (-1);
	return (1);
}

static int	check_minus(unsigned int unum, t_flags *fg, char *buff, int *index)
{
	if (fg->minus == 1)
	{
		if (check_hash(fg, unum, buff, index) == -1)
			return (-1);
		if (fg->perc > fg->slen && unum != 0)
		{
			while (fg->perc - fg->slen + fg->hash > fg->tlen)
				check_buffer(buff, index, '0', fg);
		}
		else if (fg->perc > fg->slen && unum == 0)
		{
			while (fg->perc - fg->slen > fg->tlen)
				check_buffer(buff, index, '0', fg);
		}
		if (print_base_h(unum, fg, &buff, index) == -1)
			return (-1);
		while (fg->len > fg->tlen)
			check_buffer(buff, index, ' ', fg);
	}
	else if (check_front(unum, fg, buff, index) == -1)
		return (-1);
	return (1);
}

int	ft_puthex_bonus(unsigned int unum, char *str, t_flags *fg)
{
	char	buff[4096];
	int		index;

	index = 0;
	if (unum == 0)
		fg->nul = 1;
	fg->slen = get_number_size((uintptr_t)unum, 16);
	fg->base = str;
	if (check_minus(unum, fg, buff, &index) == -1)
		return (-1);
	if (write(1, buff, index) == -1)
		return (-1);
	return (fg->tlen);
}
