/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:00:00 by likong            #+#    #+#             */
/*   Updated: 2024/06/20 09:50:02 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

static mlx_image_t	*load_image(t_game *g, const char *path)
{
	mlx_texture_t	*tex;
	mlx_image_t		*img;

	tex = mlx_load_png(path);
	if (!tex)
		show_error(g, "Failed to load image.");
	img = mlx_texture_to_image(g->disp.mlx, tex);
	mlx_delete_texture(tex);
	if (!img)
		show_error(g, "Allocation error on read texture.");
	if (!mlx_resize_image(img, g->tile, g->tile))
		show_error(g, "Failed to resize image.");
	return (img);
}

static void	save_image(t_game *g)
{
	check_tile(g);
	g->img = malloc(NUM_IMAGE * sizeof(mlx_image_t));
	if (!g->img)
		show_error(g, "Allocation error on read texture.");
	g->img[W1] = load_image(g, "./assets/wall/wall.png");
	g->img[S1] = load_image(g, "./assets/floors/floor1.png");
	g->img[C1] = load_image(g, "./assets/chest/1.png");
	g->img[E1] = load_image(g, "./assets/floors/door1.png");
	g->img[E2] = load_image(g, "./assets/floors/door2.png");
	g->img[P1] = load_image(g, "./assets/floors/start.png");
	g->img[P2] = load_image(g, "./assets/player/1.png");
}

static void	init_graph(t_game *g)
{
	g->disp.width = g->map->cols * BLOCK_SIZE;
	g->disp.height = g->map->rows * BLOCK_SIZE;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	g->disp.mlx = mlx_init(g->disp.width, g->disp.height, "so_long", true);
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
	save_image(&g);
	draw_map(&g);
	mlx_key_hook(g.disp.mlx, keyhook, &g);
	mlx_close_hook(g.disp.mlx, closehook, &g);
	//mlx_loop_hook(g.disp.mlx, &render_frame, &g);
	mlx_loop(g.disp.mlx);
	//mlx_terminate(g.disp.mlx);
}
