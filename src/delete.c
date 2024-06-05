/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:16:45 by likong            #+#    #+#             */
/*   Updated: 2024/06/05 10:48:37 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	delete_teximage(t_game *g)
{
	int	i;

	i = 0;
	while (i < NUM_IMAGE)
		mlx_delete_texture(g->tex[i++]);
	free(g->tex);
}

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
	if (g->tex)
		delete_teximage(g);
	if (g->map)
		delete_map(g->map);
	mlx_terminate(g->disp.mlx);
}
