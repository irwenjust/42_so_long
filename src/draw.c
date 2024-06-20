/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:13:44 by likong            #+#    #+#             */
/*   Updated: 2024/06/20 11:00:08 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

static void	add_image(t_game *g, mlx_image_t *img, t_point p)
{
	if (mlx_image_to_window(g->disp.mlx, img, p.x * g->tile, p.y * g->tile) < 0)
		show_error(g, "cannot draw image to windows.");
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
	{
		add_image(g, g->img[E2], p);
		add_image(g, g->img[E1], p);
		g->exit.x = p.x;
		g->exit.y = p.y;
	}
	else if (g->map->cont[p.y][p.x] == SPACE)
		add_image(g, g->img[S1], p);
	else if (g->map->cont[p.y][p.x] == PLAYER)
	{
		add_image(g, g->img[P1], p);
		g->curr.x = p.x;
		g->curr.y = p.y;
	}
}

void	draw_map(t_game *g)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (++y < g->map->rows)
	{
		x = -1;
		while (++x < g->map->cols)
			draw_image(g, (t_point){x, y});
	}
	add_image(g, g->img[P2], g->curr);
}
