/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:13:26 by likong            #+#    #+#             */
/*   Updated: 2024/04/17 15:13:27 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str1_o = "abcde";
	char *str2_o = "abcd";
	char *str1_f = "abcde";
	char *str2_f = "abcd";
  	printf("The original: %d\n", memcmp(str1_o, str2_o, 5));
	printf("The ft_memcmp: %d\n", ft_memcmp(str1_f, str2_f, 5));
	printf("The original: %d\n", memcmp("abcde", "abcd", 5));
	printf("The ft_memcmp: %d\n", ft_memcmp("abcde", "abcd", 5));
  	return (0);
}
*/
