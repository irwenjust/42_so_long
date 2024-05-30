/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:23:22 by likong            #+#    #+#             */
/*   Updated: 2024/04/17 16:36:02 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if ((size_t)dst - (size_t)src >= len)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i-- > 0)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "Hello, world!";

    char dst_memmove_f[20];
	char dst_memmove_o[20];
	

    ft_memmove(dst_memmove_f, src, strlen(src));
	memmove(dst_memmove_o, src, strlen(src));
	//ft_memmove(dst_memmove_f+1, src, strlen(src) + 1);

    printf("Using memmove: %s\n", dst_memmove_o);
	printf("Using ft_memmove: %s\n", dst_memmove_f);

    return 0;

}
*/
