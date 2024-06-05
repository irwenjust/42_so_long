/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:13:44 by likong            #+#    #+#             */
/*   Updated: 2024/06/05 11:38:51 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

static void	check_tile(t_game *g)
{
	unsigned int	height;
	unsigned int	width;

	width = WIDTH / g->map->cols;
	height = HEIGHT / g->map->rows;
	if (width <= height)
		g->tile = width;
	else
		g->tile = height;
}

static void	draw_player(t_game *g, t_point p)
{
	mlx_image_t *img = NULL;

	img = mlx_texture_to_image(g->disp.mlx, g->tex[P2]);
	if (!img)
		show_error(g, "cannot draw the player.");
	mlx_resize_image(img, g->tile, g->tile);
	if (mlx_image_to_window(g->disp.mlx, img, p.x * g->tile, p.y * g->tile) < 0)
        show_error(g, "cannot draw image to windows.");
}

static void	draw_image(t_game *g, t_point p)
{
	mlx_image_t *img = NULL;

	if (g->map->cont[p.y][p.x] == WALL)
		img = mlx_texture_to_image(g->disp.mlx, g->tex[W1]);
	else if (g->map->cont[p.y][p.x] == CHEST)
		img = mlx_texture_to_image(g->disp.mlx, g->tex[C1]);
	else if (g->map->cont[p.y][p.x] == EXIT)
		img = mlx_texture_to_image(g->disp.mlx, g->tex[E1]);
	else if (g->map->cont[p.y][p.x] == SPACE)
		img = mlx_texture_to_image(g->disp.mlx, g->tex[S1]);
	else if (g->map->cont[p.y][p.x] == START)
		img = mlx_texture_to_image(g->disp.mlx, g->tex[P1]);
	if (!img)
		show_error(g, "cannot draw the image.");
	mlx_resize_image(img, g->tile, g->tile);
	if (mlx_image_to_window(g->disp.mlx, img, p.x * g->tile, p.y * g->tile) < 0)
        show_error(g, "cannot draw image to windows.");
	if (g->map->cont[p.y][p.x] == START)
		draw_player(g, p);
}

void	draw_map(t_game *g)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	check_tile(g);
	while (++y < g->map->rows)
	{
		x = -1;
		while (++x < g->map->cols)
			draw_image(g, (t_point){x, y});
	}
}
