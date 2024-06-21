/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:09:17 by likong            #+#    #+#             */
/*   Updated: 2024/06/13 14:19:15 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*str_chr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*str_join(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	c;
	size_t	size;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	size = str_len(s1, '\0') + str_len(s2, '\0');
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	return (str);
}

size_t	str_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*substr(const char *s, size_t start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
		return (0);
	if (start > str_len(s, '\0'))
	{
		res = malloc(sizeof(char) * (1));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (str_len(s, '\0') - start < len)
		len = str_len(s, '\0') - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < str_len(s, '\0') && i < len && s[start])
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
