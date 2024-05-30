/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:06:12 by likong            #+#    #+#             */
/*   Updated: 2024/04/16 16:06:13 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	size_t i = 0;
	void *a = malloc(10 * sizeof(char));
	ft_bzero(a, 10);
	while (i < 10)
		printf("%c", (char *)a[i++]);
	free(a);
	return (0);
}
*/
