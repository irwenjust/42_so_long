/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:13:44 by likong            #+#    #+#             */
/*   Updated: 2024/07/01 17:40:26 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

static void	add_image(t_game *g, mlx_image_t *img, t_point p)
{
	if (mlx_image_to_window(g->disp.mlx, img, p.x * g->tile, p.y * g->tile) < 0)
		show_error(g, "cannot draw image to windows.");
}

static void	add_exit(t_game *g, t_point p)
{
	add_image(g, g->img[E2], p);
	add_image(g, g->img[E1], p);
	g->exit.x = p.x;
	g->exit.y = p.y;
}

static void	save_enemy_position(t_game *g, t_point p)
{
	static uint32_t	i = 0;

	g->enemy_p[i].x = p.x;
	g->enemy_p[i].y = p.y;
	i++;
}

void	draw_image(t_game *g, t_point p)
{
	if (g->map->cont[p.y][p.x] == WALL)
		add_image(g, g->img[W1], p);
	else if (g->map->cont[p.y][p.x] == CHEST)
	{
		add_image(g, g->img[S1], p);
		add_image(g, g->img[C1], p);
	}
	else if (g->map->cont[p.y][p.x] == EXIT)
		add_exit(g, p);
	else if (g->map->cont[p.y][p.x] == SPACE)
		add_image(g, g->img[S1], p);
	else if (g->map->cont[p.y][p.x] == ENEMY)
	{
		add_image(g, g->img[S1], p);
		save_enemy_position(g, p);
	}
	else if (g->map->cont[p.y][p.x] == PLAYER)
	{
		add_image(g, g->img[PS], p);
		g->curr.x = p.x;
		g->curr.y = p.y;
	}
}

void	draw_map(t_game *g)
{
	unsigned int	x;
	unsigned int	y;
	t_point			*p;

	p = (t_point *)malloc((g->map->enemys) * sizeof(t_point));
	if (!p)
		show_error(g, "cannot allpy space for enemy position.");
	y = -1;
	g->enemy_p = p;
	while (++y < g->map->rows)
	{
		x = -1;
		while (++x < g->map->cols)
			draw_image(g, (t_point){x, y});
	}
	y = -1;
	while (++y < g->map->enemys)
		add_image(g, g->img[D1], (t_point){g->enemy_p[y].x, g->enemy_p[y].y});
	add_image(g, g->img[PU], g->curr);
	add_image(g, g->img[PD], g->curr);
	add_image(g, g->img[PL], g->curr);
	add_image(g, g->img[PR], g->curr);
	g->img[PU]->instances[0].enabled = false;
	g->img[PD]->instances[0].enabled = false;
	g->img[PL]->instances[0].enabled = false;
}
