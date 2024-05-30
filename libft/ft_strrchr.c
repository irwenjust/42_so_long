/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:06:28 by likong            #+#    #+#             */
/*   Updated: 2024/04/17 14:06:29 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((char *)s + i);
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
  char *s1 = strrchr("123456", 0);
  char *s2 = ft_strrchr("123456", 0);
  printf("The original: %s\n", s1);
  printf("The ft_strrchr: %s\n", s2);
  return (0);
}
*/
