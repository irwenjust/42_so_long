/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:16:06 by likong            #+#    #+#             */
/*   Updated: 2024/06/26 13:54:59 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

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
		g->img[P2]->instances[0].x = g->next.x * g->tile;
		g->img[P2]->instances[0].y = g->next.y * g->tile;
		g->curr = g->next;
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

void	move_player(t_game *g)
{
	if (!is_valid_move(g))
		return ;
	if (is(g, g->next) == CHEST)
	{
		g->map->cont[g->curr.y][g->curr.x] = SPACE;
		g->coins++;
		check_chest(g);
	}
	else if (is(g, g->next) == EXIT && g->coins == g->map->chests)
	{
		ft_printf("You win!\n");
		quit(g);
	}
	g->map->cont[g->curr.y][g->curr.x] = SPACE;
	g->map->cont[g->next.y][g->next.x] = PLAYER;
	ft_printf("Moves: %u, coins: %u\n", ++g->moves, g->coins);
	g->img[P2]->instances[0].x = g->next.x * g->tile;
	g->img[P2]->instances[0].y = g->next.y * g->tile;
	g->curr = g->next;
}
