/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:07:14 by likong            #+#    #+#             */
/*   Updated: 2024/04/16 15:07:16 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
		((unsigned char *)b)[i++] = c;
	return (b);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	size_t i = 0;
	void *a = malloc(10 * sizeof(char));
	char *c = ft_memset(a, 0, 10);
	while (i < 10)
		printf("%c", c[i++]);
	free(a);
	return (0);
}
*/
