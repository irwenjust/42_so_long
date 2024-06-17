/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:16:06 by likong            #+#    #+#             */
/*   Updated: 2024/06/17 18:37:18 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

bool	is_valid_move(t_game *g)
{
	return (!is_same_point(g->curr, g->next) && is(g, g->next) != WALL);
}

void	move_player(t_game *g)
{
	static t_char prev = SPACE;

	if (!is_valid_move(g))
		return ;
	g->map->cont[g->curr.y][g->curr.x] = prev;
	if (is(g, g->next) != CHEST)
		prev = g->map->cont[g->next.y][g->next.x];
	else
		prev = SPACE;
	if (is(g, g->next) == CHEST)
		g->coins++;
	else if (is(g, g->next) == EXIT && g->coins == g->map->chests)
		quit(g);
	g->map->cont[g->next.y][g->next.x] = PLAYER;
	//ft_printf("Moves: %u\n", ++(g->moves));
	draw_image(g, (t_point){g->curr.x, g->curr.y});
	draw_image(g, (t_point){g->next.x, g->next.y});
	ft_printf("curr: (%d, %d), next: (%d, %d), coins: %d, cont: %c\n", g->curr.x, g->curr.y, g->next.x, g->next.y, g->coins, is(g, g->next));
	g->curr = g->next;
}
