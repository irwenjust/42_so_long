/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:27:48 by likong            #+#    #+#             */
/*   Updated: 2024/05/28 14:30:01 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_zero_dot(uintptr_t address, t_flags *fg)
{
	int	j;

	j = 0;
	if (write(1, "0x", 2) != 2)
		return (-1);
	fg->tlen += 2;
	if (fg->perc > fg->slen)
	{
		while (fg->slen + j++ < fg->perc)
			if (put_char('0', fg) == -1)
				return (-1);
	}
	else if (fg->zero > 0 && fg->len > fg->slen + 2
		&& fg->perc == 0)
	{
		while (fg->len > fg->slen + 2 + j++)
			if (put_char('0', fg) == -1)
				return (-1);
	}
	if (fg->nul != 1)
		if (print_number_base(address, HEXL, fg) == -1)
			return (-1);
	return (1);
}

static int	check_front(uintptr_t address, t_flags *fg)
{
	if (fg->len > 0 && fg->perc > 0)
	{
		while (fg->len > fg->perc + 2 + fg->tlen
			&& fg->len > fg->slen + 2 + fg->tlen)
			if (put_char(' ', fg) == -1)
				return (-1);
	}
	else if (fg->len > 0 && fg->perc == 0 && fg->zero == 0)
	{
		while (fg->len > fg->slen + 2 + fg->tlen)
			if (put_char(' ', fg) == -1)
				return (-1);
	}
	if (check_zero_dot(address, fg) == -1)
		return (-1);
	return (1);
}

static int	check_minus(uintptr_t address, t_flags *fg)
{
	if (fg->minus == 1)
	{
		if (write(1, "0x", 2) != 2)
			return (-1);
		if (fg->perc > fg->slen)
			while (fg->perc - fg->slen > fg->tlen)
				if (put_char('0', fg) == -1)
					return (-1);
		fg->tlen += 2;
		if (fg->nul != 1)
			if (print_number_base(address, HEXL, fg) == -1)
				return (-1);
		while (fg->len > fg->tlen)
			if (put_char(' ', fg) == -1)
				return (-1);
	}
	else
		if (check_front(address, fg) == -1)
			return (-1);
	return (1);
}

int	ft_putpoint_bonus(void *str, t_flags *fg)
{
	uintptr_t	address;

	address = (uintptr_t)str;
	if (address == 0 && fg->dot == 1)
		fg->nul = 1;
	fg->slen = get_number_size(address, 16);
	if (check_minus(address, fg) == -1)
		return (-1);
	return (fg->tlen);
}
