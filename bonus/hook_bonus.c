/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:18:35 by likong            #+#    #+#             */
/*   Updated: 2024/06/27 12:28:31 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		quit(g);
	if (g->state == WIN || g->state == FAIL)
		return ;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
		&& g->p_state == STOP)
		check_player_up_down(g, GO_UP);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
		&& g->p_state == STOP)
		check_player_up_down(g, GO_DOWN);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
		&& g->p_state == STOP)
		check_player_left_right(g, GO_LEFT);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& g->p_state == STOP)
		check_player_left_right(g, GO_RIGHT);
}

void	closehook(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	delete_game(g);
	exit(EXIT_SUCCESS);
}

static void	control_game(t_game *g, double time)
{
	update_player(g, time);
	update_coin(g, time);
	update_enemy(g);
}

void	update(void *param)
{
	t_game	*g;
	double	time;

	g = (t_game *)param;
	time = g->disp.mlx->delta_time;
	if (g->state == RUNNING)
		control_game(g, time);
}
