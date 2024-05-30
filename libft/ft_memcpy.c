/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:13:14 by likong            #+#    #+#             */
/*   Updated: 2024/04/16 16:13:18 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool compareMemory(void *ptr1, void *ptr2, size_t n) {
    return memcmp(ptr1, ptr2, n) == 0;
}

int main() {
    char src[] = "Hello, world!";
    char dst1[20];
    char dst2[20];

    ft_memcpy(dst1, src, strlen(src) + 1);

    memcpy(dst2, src, strlen(src) + 1);

    bool result = compareMemory(dst1, dst2, strlen(src) + 1);

    if (result) {
        printf("Memory copied correctly.\n");
    } else {
        printf("Error: Memory not copied correctly.\n");
    }

    return 0;
}*/
