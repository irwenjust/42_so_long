/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:01:25 by likong            #+#    #+#             */
/*   Updated: 2024/04/18 18:01:25 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	len;

	if (!s || !f)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>

// Function to print the index and character of each character in the string
void print_index_and_char(unsigned int index, char *c) {
    printf("Index: %u, Character: %c\n", index, *c);
}

int main()
{
    // Test case 1: Passing a null pointer for the string s
    printf("Test Case 1: Passing a null pointer for the string s\n");
    ft_striteri(NULL, &print_index_and_char);

    // Test case 2: Passing a null pointer for the function pointer f
    printf("\nTest Case 2: Passing a null pointer for the function pointer f\n");
    char str[] = "Hello";
    ft_striteri(str, NULL);

    // Test case 3: Passing a valid string and function pointer
    printf("\nTest Case 3: Passing a valid string and function pointer\n");
    ft_striteri(str, &print_index_and_char);

    return 0;
}
*/
