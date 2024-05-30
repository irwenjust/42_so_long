/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:17:47 by likong            #+#    #+#             */
/*   Updated: 2024/04/18 22:17:48 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*clean_work(t_list	**res, void (*del)(void *))
{
	ft_lstclear(res, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*list_node;
	void	*list_content;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		list_content = f(lst->content);
		if (!list_content)
			return (clean_work(&res, del));
		list_node = ft_lstnew(list_content);
		if (!list_node)
		{
			del(list_content);
			return (clean_work(&res, del));
		}
		ft_lstadd_back(&res, list_node);
		lst = lst->next;
	}
	return (res);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *square_number(void *content)
{
    int *num = (int *)content;
    int *result = malloc(sizeof(int));
    if (result)
        *result = (*num) * (*num);
    return result;
}

int main()
{
    t_list *head = NULL;
    t_list *node1 = ft_lstnew(malloc(sizeof(int)));
    *(int *)node1->content = 0;
    t_list *node2 = ft_lstnew(malloc(sizeof(int)));
    *(int *)node2->content = 1;
    t_list *node3 = ft_lstnew(malloc(sizeof(int)));
    *(int *)node3->content = 2;

    ft_lstadd_front(&head, node1);
    ft_lstadd_front(&head, node2);
    ft_lstadd_front(&head, node3);

    t_list *new_list = ft_lstmap(head, &square_number, &free);

    printf("New list after mapping:\n");
    t_list *current = new_list;
    while (current)
    {
        printf("%d\n", *(int *)current->content);
        current = current->next;
    }

    ft_lstclear(&head, &free);
    ft_lstclear(&new_list, &free);

    return 0;
}
*/
