/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:36:28 by likong            #+#    #+#             */
/*   Updated: 2024/04/18 17:36:29 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s || !f)
		return (NULL);
	i = 0;
	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
#include <ctype.h>
#include <stdio.h>

char transform_char(unsigned int index, char c) {
    if (index % 2 == 0) {
        return toupper(c);  // Convert even-indexed characters to uppercase
    } else {
        return tolower(c);  // Convert odd-indexed characters to lowercase
    }
}

int main() {
    char input[] = "Hello, World!";
    char *result = ft_strmapi(input, &transform_char);
    printf("%s\n", result);  // Output: "HeLlO, WoRlD!"
    free(result); // Don't forget to free the memory allocated by ft_strmapi
    return 0;
}
*/
