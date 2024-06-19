/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:16:06 by likong            #+#    #+#             */
/*   Updated: 2024/06/19 14:26:46 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

bool	is_valid_move(t_game *g)
{
	if (is_same_point(g->curr, g->next))
		return (false);
	else if (is(g, g->next) == WALL)
	{
		ft_printf("Please don't banging wall.\n");
		return (false);
	}
	else if (is_same_point(g->curr, g->exit) 
		&& g->coins != g->map->chests
		&& is(g, g->next) != WALL)
	{
		g->map->cont[g->curr.y][g->curr.x] = EXIT;
		g->map->cont[g->next.y][g->next.x] = PLAYER;
		ft_printf("Moves: %u, coins: %u\n", ++g->moves, g->coins);
		draw_image(g, (t_point){g->curr.x, g->curr.y});
		draw_image(g, (t_point){g->next.x, g->next.y});
		g->curr = g->next;
		return (false);
	}
	return (true);
}

static void	open_exit(t_game *g)
{
	mlx_image_t *img = NULL;

	img = mlx_texture_to_image(g->disp.mlx, g->tex[E2]);
	if (!img)
		show_error(g, "cannot draw the image.");
	mlx_resize_image(img, g->tile, g->tile);
	if (mlx_image_to_window(g->disp.mlx, img, g->exit.x * g->tile, g->exit.y * g->tile) < 0)
        show_error(g, "cannot draw image to windows.");
}

static void	face_enemy(t_game *g)
{
	ft_printf("You lose.\n");
	quit(g);
}

void	move_player(t_game *g)
{
	static t_char prev = SPACE;

	if (!is_valid_move(g))
		return ;
	g->map->cont[g->curr.y][g->curr.x] = prev;
	if (is(g, g->next) == ENEMY)
		face_enemy(g);
	if (is(g, g->next) != CHEST && is(g, g->next) != EXIT)
		prev = g->map->cont[g->next.y][g->next.x];
	else if (is(g, g->next) == CHEST)
	{
		prev = SPACE;
		g->coins++;
		if (g->coins == g->map->chests)
			open_exit(g);
	}
	else if (is(g, g->next) == EXIT && g->coins == g->map->chests)
	{
		ft_printf("You win!\n");
		quit(g);
	}
	g->map->cont[g->next.y][g->next.x] = PLAYER;
	draw_image(g, (t_point){g->curr.x, g->curr.y});
	draw_image(g, (t_point){g->next.x, g->next.y});
	g->curr = g->next;
}
