/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:16:45 by likong            #+#    #+#             */
/*   Updated: 2024/05/31 13:22:32 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	delete_map(t_map *map)
{
	if (!map)
		return ;
	del_matrix(map->cont);
	free(map);
}

void	delete_game(t_game *g)
{
	if (!g)
		return ;
	if (g->map)
		delete_map(g->map);
}
