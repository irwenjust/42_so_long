/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:43:17 by likong            #+#    #+#             */
/*   Updated: 2024/06/26 14:06:32 by likong           ###   ########.fr       */
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

void	update_counter(t_game *g)
{
	char	*nbr;

	nbr = ft_itoa((int)g->moves);
	if (g->img[U1] == NULL)
	{
		g->img[T1] = mlx_put_string(g->disp.mlx, "Moves: ", PADDING, PADDING);
		g->img[U1] = mlx_put_string(g->disp.mlx,
				nbr, BLOCK_SIZE + PADDING, PADDING);
		free(nbr);
		return ;
	}
	mlx_delete_image(g->disp.mlx, g->img[U1]);
	g->img[U1] = mlx_put_string(g->disp.mlx,
			nbr, BLOCK_SIZE + PADDING, PADDING);
	free(nbr);
}

void	update_coin(t_game *g, double time)
{
	static double	local_time = 0;
	static int32_t	current = 0;
	uint32_t		w;
	uint32_t		h;

	local_time += time;
	if (current >= 12)
		current = 0;
	if (local_time > 0.08)
	{
		h = 0;
		while (h < g->img[C1]->height)
		{
			w = 0;
			while (w < g->img[C1]->width)
			{
				mlx_put_pixel(g->img[C1], w, h,
					get_pixel(g->spr_c->img, current * 64 + w, h));
				w++;
			}
			h++;
		}
		current++;
		local_time -= 0.08;
	}
}

void	update_player(t_game *g)
{
	static unsigned int	dist = 0;
	t_image				img;

	img = PU;
	if (g->p_state != STOP && dist >= g->tile)
	{
		g->p_state = STOP;
		g->curr = g->next;
		dist = 0;
		return ;
	}
	if (g->p_state != STOP && dist < g->tile)
	{
		while (img <= PR)
		{
			g->img[img]->instances[0].x = (g->curr.x * g->tile)
				+ (dist * (g->next.x - g->curr.x));
			g->img[img]->instances[0].y = (g->curr.y * g->tile)
				+ (dist * (g->next.y - g->curr.y));
			dist += 0.025 * g->tile;
			img++;
		}
	}
}
