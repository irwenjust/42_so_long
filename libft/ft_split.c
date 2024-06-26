/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:32:05 by likong            #+#    #+#             */
/*   Updated: 2024/06/26 18:02:10 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_length(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	count_array(char *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	array_amount;

	i = 0;
	array_amount = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		len = str_length(s + i, c);
		if (len > 0)
			array_amount++;
		i += len;
	}
	return (array_amount);
}

static void	*free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	j;
	size_t	array_amount;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	array_amount = count_array((char *)s, c);
	strs = (char **)malloc((array_amount + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (j < array_amount)
	{
		while (s[i] == c)
			i++;
		strs[j] = ft_substr(s, i, str_length((char *)s + i, c));
		if (!strs[j])
			return (free_strs(strs));
		i += str_length((char *)s + i, c);
		j++;
	}
	strs[j] = NULL;
	return (strs);
}
