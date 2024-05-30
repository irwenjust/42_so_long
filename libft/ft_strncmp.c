/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:07:09 by likong            #+#    #+#             */
/*   Updated: 2024/04/19 10:07:10 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (i >= n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s1_o = "12345";
	char *s2_o = "";
	char *s1_f = "12345";
	char *s2_f = "";

	printf("ori function: %d\n", strncmp(s1_o, s2_o, 3));
	printf("ft_strncmp: %d\n", ft_strncmp(s1_f, s2_f, 3));
	return (0);
}
*/
