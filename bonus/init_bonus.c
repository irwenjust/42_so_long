/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:00:00 by likong            #+#    #+#             */
/*   Updated: 2024/06/27 08:21:45 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

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
	if (ft_strncmp(path, "./assets/result/win.png", 30)
		&& ft_strncmp(path, "./assets/result/lose.png", 30))
	{
		if (!mlx_resize_image(img, g->tile, g->tile))
			show_error(g, "Failed to resize image.");
	}
	return (img);
}

static t_sprite	*load_spr(t_game *g, char *path, uint32_t rows, uint32_t cols)
{
	mlx_texture_t	*tex;
	t_sprite		*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	tex = mlx_load_png(path);
	if (!tex)
		show_error(g, "Failed to load sprite.");
	sprite->img = mlx_texture_to_image(g->disp.mlx, tex);
	mlx_delete_texture(tex);
	if (!sprite->img)
		show_error(g, "Allocation error on read texture.");
	if (!mlx_resize_image(sprite->img, g->tile * cols, g->tile * rows))
		show_error(g, "Failed to resize image.");
	sprite->rows = rows;
	sprite->cols = cols;
	return (sprite);
}

static void	save_image(t_game *g)
{
	check_tile(g);
	g->img = malloc(NUM_IMAGE * sizeof(mlx_image_t));
	if (!g->img)
		show_error(g, "Allocation error on read texture.");
	g->img[W1] = load_image(g, "./assets/wall/wall.png");
	g->img[S1] = load_image(g, "./assets/floors/floor1.png");
	g->img[E1] = load_image(g, "./assets/floors/door1.png");
	g->img[E2] = load_image(g, "./assets/floors/door2.png");
	g->img[PS] = load_image(g, "./assets/floors/start.png");
	g->img[PR] = load_image(g, "./assets/player/right.png");
	g->img[PL] = load_image(g, "./assets/player/left.png");
	g->img[PU] = load_image(g, "./assets/player/up.png");
	g->img[PD] = load_image(g, "./assets/player/down.png");
	g->img[D1] = load_image(g, "./assets/enemy/enemy.png");
	g->img[RW] = load_image(g, "./assets/result/win.png");
	g->img[RL] = load_image(g, "./assets/result/lose.png");
	g->img[U1] = NULL;
	g->img[T1] = NULL;
	g->img[C1] = mlx_new_image(g->disp.mlx, BLOCK_SIZE, BLOCK_SIZE);
	g->spr_c = load_spr(g, "./assets/chest/coin.png", 1, 12);
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
	update_counter(&g);
	mlx_key_hook(g.disp.mlx, keyhook, &g);
	mlx_close_hook(g.disp.mlx, closehook, &g);
	mlx_loop_hook(g.disp.mlx, update, &g);
	mlx_loop(g.disp.mlx);
	g.state = RUNNING;
}
