/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:17:03 by likong            #+#    #+#             */
/*   Updated: 2024/04/18 17:17:04 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int		size;
	long	num;

	size = 1;
	num = n;
	if (n < 0)
	{
		size++;
		num = -num;
	}
	while (num >= 10)
	{
		num /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	num;

	len = get_len(n);
	num = n;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	else if (num == 0)
	{
		res[0] = '0';
	}
	res[len--] = '\0';
	while (num > 0)
	{
		res[len--] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("%s\n", ft_itoa(0));
	return (0);
}
*/
