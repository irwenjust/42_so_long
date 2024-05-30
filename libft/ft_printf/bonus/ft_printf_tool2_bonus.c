/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:02:11 by likong            #+#    #+#             */
/*   Updated: 2024/05/28 14:29:47 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_base_h(uintptr_t nbr, t_flags *fg, char **buff, int *index)
{
	unsigned int	base_len;

	if (fg->nul == 1 && fg->perc == 0 && fg->dot == 1 && fg->len > 0)
	{
		if (*index < fg->len)
			check_buffer(*buff, index, ' ', fg);
		return (1);
	}
	else if (fg->nul == 1 && fg->perc == 0 && fg->dot == 1 && fg->len == 0)
		return (0);
	base_len = str_length(fg->base);
	if (nbr >= base_len)
	{
		print_base_h(nbr / base_len, fg, buff, index);
		print_base_h(nbr % base_len, fg, buff, index);
	}
	else
		check_buffer(*buff, index, fg->base[nbr], fg);
	return (1);
}

void	check_buffer(char *buff, int *index, char c, t_flags *fg)
{
	if (*index >= 4096)
	{
		write(1, buff, *index);
		*index = 0;
	}
	buff[(*index)++] = c;
	fg->tlen++;
}
