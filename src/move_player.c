/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:16:06 by likong            #+#    #+#             */
/*   Updated: 2024/06/18 14:09:24 by likong           ###   ########.fr       */
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
	else if ((is(g, g->next) == EXIT && g->coins != g->map->chests))
	{
		ft_printf("Please collect all of coins.");
		ft_printf("Still need %d more.\n", g->map->chests - g->coins);
		return (false);
	}
	return (true);
}

void	move_player(t_game *g)
{
	static t_char prev = SPACE;

	if (!is_valid_move(g))
		return ;
	g->map->cont[g->curr.y][g->curr.x] = prev;
	if (is(g, g->next) != CHEST && is(g, g->next) != EXIT)
		prev = g->map->cont[g->next.y][g->next.x];
	else if (is(g, g->next) == CHEST)
	{
		prev = SPACE;
		g->coins++;
	}
	else if (is(g, g->next) == EXIT && g->coins == g->map->chests)
	{
		ft_printf("You win!\n");
		quit(g);
	}
	g->map->cont[g->next.y][g->next.x] = PLAYER;
	ft_printf("Moves: %u, coins: %u\n", ++g->moves, g->coins);
	draw_image(g, (t_point){g->curr.x, g->curr.y});
	draw_image(g, (t_point){g->next.x, g->next.y});
	g->curr = g->next;
}
