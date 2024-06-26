/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:16:06 by likong            #+#    #+#             */
/*   Updated: 2024/06/26 16:04:05 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

static bool	is_valid_move(t_game *g)
{
	if (is_same_point(g->curr, g->next))
		return (false);
	else if (is(g, g->next) == WALL)
	{
		g->p_state = STOP;
		ft_printf("Please don't banging wall.\n");
		return (false);
	}
	return (true);
}

static void	check_chest(t_game *g)
{
	size_t	i;

	i = 0;
	while (i < g->img[C1]->count)
	{
		if (g->img[C1]->instances[i].x == (int)(g->next.x * g->tile)
			&& g->img[C1]->instances[i].y == (int)(g->next.y * g->tile))
		{
			g->img[C1]->instances[i].enabled = false;
			break ;
		}
		i++;
	}
	if (g->coins == g->map->chests)
		g->img[E1]->instances[0].enabled = false;
}

static void	face_enemy(t_game *g)
{
	if (!mlx_resize_image(g->img[RL], g->disp.width, g->disp.height))
		show_error(g, "Failed to resize image.");
	if (mlx_image_to_window(g->disp.mlx, g->img[RL], 0, 0) < 0)
		show_error(g, "cannot draw image to windows.");
	g->state = FAIL;
}

static void	face_win(t_game *g)
{
	if (!mlx_resize_image(g->img[RW], g->disp.width, g->disp.height))
		show_error(g, "Failed to resize image.");
	if (mlx_image_to_window(g->disp.mlx, g->img[RW], 0, 0) < 0)
		show_error(g, "cannot draw image to windows.");
	g->state = WIN;
}

void	move_player(t_game *g)
{
	if (!is_valid_move(g))
		return ;
	if (is(g, g->next) == ENEMY)
		face_enemy(g);
	if (is(g, g->next) == CHEST)
	{
		g->map->cont[g->curr.y][g->curr.x] = SPACE;
		g->coins++;
		check_chest(g);
	}
	else if (is(g, g->next) == EXIT && g->coins == g->map->chests)
		face_win(g);
	g->map->cont[g->curr.y][g->curr.x] = SPACE;
	g->map->cont[g->next.y][g->next.x] = PLAYER;
	g->moves++;
}
