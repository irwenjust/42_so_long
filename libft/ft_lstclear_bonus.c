/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:41:40 by likong            #+#    #+#             */
/*   Updated: 2024/04/18 21:41:44 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*res;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		res = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(res, del);
	}
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delete_function(void *content) {
    free(content);
}

int main() {
    t_list *head = NULL;

    t_list *node1 = ft_lstnew(strdup("Node 1"));
    t_list *node2 = ft_lstnew(strdup("Node 2"));
    t_list *node3 = ft_lstnew(strdup("Node 3"));

    ft_lstadd_front(&head, node1);
    ft_lstadd_front(&head, node2);
    ft_lstadd_front(&head, node3);

    ft_lstclear(&head, delete_function);

    if (!head)
        printf("The list is empty.\n");
    else
        printf("Content: %s\n", (char *)head->content);

    return 0;
}
*/
