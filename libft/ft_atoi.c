/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:17:19 by likong            #+#    #+#             */
/*   Updated: 2024/05/01 11:11:44 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space_or_not(char c)
{
	return (c == ' ' || c == '\t'
		|| c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
}

static int	check_sign(char c, int sig)
{
	if (c == '-')
		sig = -1;
	return (sig);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sig;
	long	num;
	long	check;

	i = 0;
	num = 0;
	sig = 1;
	while (is_space_or_not(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sig = check_sign(str[i], sig);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = num * 10 + str[i++] - '0';
		if (check / 10 != num && sig == 1)
			return (-1);
		if (check / 10 != num && sig == -1)
			return (0);
		num = check;
	}
	return (sig * num);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	printf("original number: %d\n", atoi("  -1123456456465465456465"));
	printf("original number: %d\n", ft_atoi("  -1123456456465465456465"));
	return (0);
}
*/
