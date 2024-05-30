/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:40:26 by likong            #+#    #+#             */
/*   Updated: 2024/04/18 19:40:27 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	change_num_to_char(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	if (fd < 0)
		return ;
	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num < 10)
		ft_putchar_fd(change_num_to_char(num), fd);
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd(change_num_to_char(num % 10), fd);
	}
}

/*
int	main(void)
{
	ft_putnbr_fd(-10, 1);
	return  (0);
}
*/
