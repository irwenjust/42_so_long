/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:41:58 by likong            #+#    #+#             */
/*   Updated: 2024/04/18 10:41:59 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) && end > start)
		end--;
	res = ft_substr(s1, start, end - start + 1);
	if (!res)
		return (NULL);
	return (res);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *res;

	res = ft_strtrim("lorem ipsum dolor amet", "te");
	printf("the ori: %s, after ft_strtrim: %s\n", "lorem ipsum dolor amet", res);
	free(res);
	return (0);
}
*/
