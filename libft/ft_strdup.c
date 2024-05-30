/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:24:18 by likong            #+#    #+#             */
/*   Updated: 2024/04/17 22:24:19 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dup = (char *)malloc(len);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, len);
	return (dup);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    // Test case 1: Non-empty string
    const char *str1 = "Hello, world!";
    char *dup1 = ft_strdup(str1);
    if (dup1 != NULL && strcmp(dup1, str1) == 0) {
        printf("Test case 1 passed: Successfully duplicated non-empty string\n");
    } else {
        printf("Test case 1 failed\n");
    }
    free(dup1);

    // Test case 2: Empty string
    const char *str2 = "";
    char *dup2 = ft_strdup(str2);
    if (dup2 != NULL && strcmp(dup2, str2) == 0) {
        printf("Test case 2 passed: Successfully duplicated empty string\n");
    } else {
        printf("Test case 2 failed\n");
    }
    free(dup2);

    // Add more test cases as needed...

    return 0;
}
*/
