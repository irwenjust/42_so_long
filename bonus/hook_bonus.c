/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:18:35 by likong            #+#    #+#             */
/*   Updated: 2024/06/19 14:49:15 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		quit(g);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		g->next = (t_point){g->curr.x, g->curr.y - 1};
		move_player(g);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		g->next = (t_point){g->curr.x, g->curr.y + 1};
		move_player(g);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		g->next = (t_point){g->curr.x - 1, g->curr.y};
		move_player(g);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		g->next = (t_point){g->curr.x + 1, g->curr.y};
		move_player(g);
	}
}

void	closehook(void *param)
{
	t_game *g;

	g = (t_game *)param;
	delete_game(g);
	exit(EXIT_SUCCESS);
}

void	update(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	g->info = "start change";
}
