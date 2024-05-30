/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:13:16 by likong            #+#    #+#             */
/*   Updated: 2024/04/18 10:13:17 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_p;
	size_t	s2_p;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	s1_p = 0;
	s2_p = 0;
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1[s1_p])
	{
		res[s1_p] = s1[s1_p];
		s1_p++;
	}
	while (s2[s2_p])
	{
		res[s1_p + s2_p] = s2[s2_p];
		s2_p++;
	}
	res[s1_p + s2_p] = '\0';
	return (res);
}
