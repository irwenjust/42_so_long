/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:10:48 by likong            #+#    #+#             */
/*   Updated: 2024/05/28 14:29:45 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	str_length(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_num_len(int num)
{
	int	len;

	len = 0;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = str_length(s);
	if (!s)
		return (NULL);
	while (i < len + 1)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

int	get_number_size(uintptr_t num, int base_size)
{
	int			total;
	uintptr_t	nbrl;

	total = 0;
	nbrl = num;
	if (nbrl >= (uintptr_t)base_size)
	{
		total += get_number_size(nbrl / base_size, base_size);
		total += get_number_size(nbrl % base_size, base_size);
	}
	else
		total++;
	return (total);
}

int	print_number_base(uintptr_t nbr, char *base, t_flags *fg)
{
	unsigned int	base_len;
	uintptr_t		nbrl;

	nbrl = nbr;
	base_len = str_length(base);
	if (nbrl >= base_len)
	{
		print_number_base(nbrl / base_len, base, fg);
		print_number_base(nbrl % base_len, base, fg);
	}
	else
	{
		if (put_char(base[nbrl], fg) == -1)
			return (-1);
	}
	return (1);
}
