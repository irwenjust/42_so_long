/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:00:00 by likong            #+#    #+#             */
/*   Updated: 2024/06/19 14:44:36 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

static void	load_image(t_game *g)
{
	g->tex = malloc(NUM_IMAGE * sizeof(mlx_texture_t));
	if (!g->tex)
		show_error(g, "Allocation error on load image.");
	g->tex[W1] = mlx_load_png("./assets/wall/wall.png");
	g->tex[S1] = mlx_load_png("./assets/floors/floor1.png");
	g->tex[C1] = mlx_load_png("./assets/chest/1.png");
	g->tex[C2] = mlx_load_png("./assets/chest/02.png");
	g->tex[E1] = mlx_load_png("./assets/floors/door1.png");
	g->tex[E2] = mlx_load_png("./assets/floors/door2.png");
	g->tex[P1] = mlx_load_png("./assets/floors/start.png");
	g->tex[P2] = mlx_load_png("./assets/player/1.png");
	g->tex[D1] = mlx_load_png("./assets/enemy/enemy.png");
}

static void	init_graph(t_game *g)
{
	g->info = "Moves: 000";
	g->disp.width = g->map->cols * BLOCK_SIZE;
	g->disp.height = g->map->rows * BLOCK_SIZE;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	g->disp.mlx = mlx_init(g->disp.width, g->disp.height, g->info, true);
	if (!g->disp.mlx)
		show_error(g, "Allocation error on initial graph.");
}

void	init_game(char *f_name)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	init_map(&g, f_name);
	validate_map(&g);
	init_graph(&g);
	load_image(&g);
	draw_map(&g);
	mlx_key_hook(g.disp.mlx, keyhook, &g);
	mlx_close_hook(g.disp.mlx, closehook, &g);
	mlx_loop_hook(g.disp.mlx, update, &g);
	mlx_loop(g.disp.mlx);
	//mlx_terminate(g.disp.mlx);
}
