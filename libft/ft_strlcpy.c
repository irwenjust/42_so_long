/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:42:17 by likong            #+#    #+#             */
/*   Updated: 2024/04/17 09:42:18 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char dst1[20];
	char dst2[20];
	size_t	len1 = strlcpy(dst1, "123456789", 20);
	size_t	len2 = ft_strlcpy(dst2, "123456789", 20);

	printf("len: %zu, dst: %s\n", len1, dst1);
	printf("len: %zu, dst: %s\n", len2, dst2);
	return (0);
}
*/
