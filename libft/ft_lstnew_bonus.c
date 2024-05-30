/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:11:23 by likong            #+#    #+#             */
/*   Updated: 2024/04/18 20:11:24 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *content = (int *)malloc(sizeof(int));
    if (content == NULL) {
        perror("Failed to allocate memory for content");
        return 1;
    }
    *content = 123;

    t_list *node = ft_lstnew(content);

    if (node == NULL) {
        printf("Failed to create new node.\n");
        free(content);
        return 1;
    }

    printf("Content of the node: %d\n", *(int *)(node->content));

    free(content);
    free(node);

    return 0;
}
*/
