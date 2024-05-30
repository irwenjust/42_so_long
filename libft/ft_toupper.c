/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:23:00 by likong            #+#    #+#             */
/*   Updated: 2024/04/17 11:23:01 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c <= 'z' && c >= 'a')
		c = c - 32;
	return (c);
}

/*
#include <stdio.h>

int main(void)
{
	printf("orignal: %c, toupper: %c\n", 'a', ft_toupper('a'));
	return (0);
}
*/