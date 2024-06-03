/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:00:00 by likong            #+#    #+#             */
/*   Updated: 2024/06/03 14:42:38 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

static void	load_image(t_game *g)
{
	g->tex = malloc(NUM_IMAGE * sizeof(mlx_texture_t));
	if (!g->tex)
		show_error(g, "Allocation error on load image.");
	g->tex[W1] = mlx_load_png("./assets/wall/wall.png");
	g->tex[S1] = mlx_load_png("./assets/floors/floor1.png");
	g->tex[S2] = mlx_load_png("./assets/floors/floor2.png");
	g->tex[C1] = mlx_load_png("./assets/chest/01.png");
	g->tex[C2] = mlx_load_png("./assets/chest/02.png");
	g->tex[E1] = mlx_load_png("./assets/floors/door1.png");
	g->tex[E2] = mlx_load_png("./assets/floors/door2.png");
	g->tex[P1] = mlx_load_png("./assets/floors/start.png");
}

static void	init_graph(t_game *g)
{
	g->disp.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!g->disp.mlx)
		show_error(g, "Allocation error on initial graph.");
	g->disp.height = HEIGHT;
	g->disp.width = WIDTH;
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
	mlx_loop(g.disp.mlx);
}
