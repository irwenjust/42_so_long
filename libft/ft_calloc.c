/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:15:56 by likong            #+#    #+#             */
/*   Updated: 2024/04/17 22:15:58 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_space;
	void	*point;

	total_space = count * size;
	if (count > 0 && size > 0 && ((total_space / count) != size))
		return (NULL);
	point = malloc(total_space);
	if (!point)
		return (NULL);
	ft_bzero(point, total_space);
	return (point);
}

/*
#include <stdio.h>

int main() {
    // Test case 1: Allocating zero bytes
    void *ptr1 = ft_calloc(0, sizeof(int));
    if (ptr1 == NULL) {
        printf("Test case 1 passed: Successfully allocated zero bytes\n");
    } else {
        printf("Test case 1 failed\n");
    }
    free(ptr1);

    // Test case 2: Allocating a single element of a basic data type
    int *ptr2 = ft_calloc(1, sizeof(int));
    if (ptr2 != NULL && *ptr2 == 0) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
    }
    free(ptr2);

    // Add more test cases as needed...

    return 0;
}
*/
