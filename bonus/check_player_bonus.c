/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:32:53 by likong            #+#    #+#             */
/*   Updated: 2024/06/27 12:33:29 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

void	check_player_up_down(t_game *g, t_pstate state)
{
	if (state == GO_UP)
	{
		g->next = (t_point){g->curr.x, g->curr.y - 1};
		g->img[PU]->instances[0].enabled = true;
		g->img[PD]->instances[0].enabled = false;
		g->img[PL]->instances[0].enabled = false;
		g->img[PR]->instances[0].enabled = false;
		g->p_state = GO_UP;
		move_player(g);
	}
	else if (state == GO_DOWN)
	{
		g->next = (t_point){g->curr.x, g->curr.y + 1};
		g->img[PU]->instances[0].enabled = false;
		g->img[PD]->instances[0].enabled = true;
		g->img[PL]->instances[0].enabled = false;
		g->img[PR]->instances[0].enabled = false;
		g->p_state = GO_DOWN;
		move_player(g);
	}
}

void	check_player_left_right(t_game *g, t_pstate state)
{
	if (state == GO_LEFT)
	{
		g->next = (t_point){g->curr.x - 1, g->curr.y};
		g->img[PU]->instances[0].enabled = false;
		g->img[PD]->instances[0].enabled = false;
		g->img[PL]->instances[0].enabled = true;
		g->img[PR]->instances[0].enabled = false;
		g->p_state = GO_LEFT;
		move_player(g);
	}
	else if (state == GO_RIGHT)
	{
		g->next = (t_point){g->curr.x + 1, g->curr.y};
		g->img[PU]->instances[0].enabled = false;
		g->img[PD]->instances[0].enabled = false;
		g->img[PL]->instances[0].enabled = false;
		g->img[PR]->instances[0].enabled = true;
		g->p_state = GO_RIGHT;
		move_player(g);
	}
}
