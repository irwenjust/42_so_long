/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:34:07 by likong            #+#    #+#             */
/*   Updated: 2024/06/17 17:21:33 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	render_frame(void *param)
{
	t_game *g;

	g = (t_game *)param;
	if (!is_valid_move(g))
		return ;
	//ft_printf("Moves: %u\n", ++(g->moves));
	if (is(g, g->next) == CHEST)
		g->coins++;
	else if (is(g, g->next) == EXIT && g->coins == g->map->chests)
		quit(g);
	move_player(g);
	return ;
}
