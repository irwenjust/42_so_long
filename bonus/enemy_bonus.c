/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:34:10 by likong            #+#    #+#             */
/*   Updated: 2024/07/01 18:03:36 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

static t_point	random_direction(t_point point, int random)
{
	if (random == 0)
		point.y -= 1;
	else if (random == 1)
		point.y += 1;
	else if (random == 2)
		point.x -= 1;
	else if (random == 3)
		point.x += 1;
	return (point);
}

static void	move_enemy_left_right(t_game *g, mlx_instance_t *ins, int next)
{
	if (next == LEFT)
	{
		if (is(g, (t_point){((*ins).x / g->tile - 1),
				(*ins).y / g->tile}) == PLAYER)
			face_enemy(g);
		g->map->cont[(*ins).y / g->tile][(*ins).x / g->tile] = SPACE;
		g->map->cont[(*ins).y / g->tile][((*ins).x / g->tile) - 1] = ENEMY;
		(*ins).x = (*ins).x - g->tile;
		(*ins).y = (*ins).y;
	}
	else if (next == RIGHT)
	{
		if (is(g, (t_point){((*ins).x / g->tile + 1),
				(*ins).y / g->tile}) == PLAYER)
			face_enemy(g);
		g->map->cont[(*ins).y / g->tile][(*ins).x / g->tile] = SPACE;
		g->map->cont[(*ins).y / g->tile][((*ins).x / g->tile) + 1] = ENEMY;
		(*ins).x = (*ins).x + g->tile;
		(*ins).y = (*ins).y;
	}
}

static void	move_enemy_up_down(t_game *g, mlx_instance_t *ins, int next)
{
	if (next == UP)
	{
		if (is(g, (t_point){(*ins).x / g->tile,
				((*ins).y / g->tile) - 1}) == PLAYER)
			face_enemy(g);
		g->map->cont[(*ins).y / g->tile][(*ins).x / g->tile] = SPACE;
		g->map->cont[((*ins).y / g->tile) - 1][(*ins).x / g->tile] = ENEMY;
		(*ins).x = (*ins).x;
		(*ins).y = (*ins).y - g->tile;
	}
	else if (next == DOWN)
	{
		if (is(g, (t_point){(*ins).x / g->tile,
				((*ins).y / g->tile) + 1}) == PLAYER)
			face_enemy(g);
		g->map->cont[(*ins).y / g->tile][(*ins).x / g->tile] = SPACE;
		g->map->cont[((*ins).y / g->tile) + 1][(*ins).x / g->tile] = ENEMY;
		(*ins).x = (*ins).x;
		(*ins).y = (*ins).y + g->tile;
	}
}

static void	check_next_position(t_game *g, mlx_instance_t *ins)
{
	t_point	res;
	int		random;

	random = ((int)((g->disp.mlx->delta_time) * 40000) % 4) - 1;
	while (++random < 2)
	{
		res = random_direction((t_point){(*ins).x / g->tile,
				(*ins).y / g->tile}, random);
		if (is(g, res) != WALL && is(g, res) != CHEST)
		{
			move_enemy_up_down(g, ins, random);
			return ;
		}
	}
	while (random < 4)
	{
		res = random_direction((t_point){(*ins).x / g->tile,
				(*ins).y / g->tile}, random);
		if (is(g, res) != WALL && is(g, res) != CHEST)
		{
			move_enemy_left_right(g, ins, random);
			return ;
		}
		random--;
	}
}

void	check_enemy(t_game *g)
{
	uint32_t	i;

	i = 0;
	while (i < g->img[D1]->count)
	{
		check_next_position(g, &(g->img[D1]->instances[i]));
		i++;
	}
}
