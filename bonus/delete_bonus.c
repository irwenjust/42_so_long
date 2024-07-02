/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:16:45 by likong            #+#    #+#             */
/*   Updated: 2024/07/01 17:52:32 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

static void	delete_image(t_game *g)
{
	int	i;

	i = 0;
	while (i < NUM_IMAGE)
		mlx_delete_image(g->disp.mlx, g->img[i++]);
	if (g->spr_c)
	{
		mlx_delete_image(g->disp.mlx, g->spr_c->img);
		free(g->spr_c);
	}
	if (g->spr_p)
	{
		mlx_delete_image(g->disp.mlx, g->spr_p->img);
		free(g->spr_p);
	}
	free(g->img);
}

void	del_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

static void	delete_map(t_map *map)
{
	if (!map)
		return ;
	del_matrix(map->cont);
	free(map);
}

static void	delete_enemy_position(t_point *p)
{
	if (!p)
		return ;
	free(p);
}

void	delete_game(t_game *g)
{
	if (!g)
		return ;
	if (g->img)
		delete_image(g);
	if (g->enemy_p)
		delete_enemy_position(g->enemy_p);
	if (g->map)
		delete_map(g->map);
	if (g->disp.mlx)
		mlx_terminate(g->disp.mlx);
}
