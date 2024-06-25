/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:43:17 by likong            #+#    #+#             */
/*   Updated: 2024/06/25 16:29:14 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

void	update_counter(t_game *g)
{
	char *nbr;

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

void	handle_coin(t_game *g, double time)
{
	static double local_time = 0;
	static int32_t	current = 0;

	local_time += time;
	if (current >= 12)
		current = 0;
	if (local_time > 0.08)
	{
		uint32_t	w;
		uint32_t	h;

		h = 0;
		while (h < g->img[C1]->height)
		{
			w = 0;
			while (w < g->img[C1]->width)
			{
				mlx_put_pixel(g->img[C1], w, h, get_pixel(g->spr_c->img, current * 64 + w, h));
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

	if (g->p_state == MOVING && dist >= g->tile)
	{
		g->p_state = STOP;
		dist = 0;
		return ;
	}
	printf("dist: %u\n", dist);
	if (g->p_state == MOVING && dist < g->tile)
	{
		g->img[P2]->instances[0].x = g->curr.x * g->tile + dist * (g->next.x - g->curr.x) / 64;
		g->img[P2]->instances[0].y = g->curr.y * g->tile + dist * (g->next.y - g->curr.y) / 64;
		dist += 0.015625 * g->tile;
	}
	
	/*unsigned int	dist;
	double			start_time;
	double			finish_time;

	dist = 0;
	start_time = g->disp.mlx->delta_time;
	finish_time = g->disp.mlx->delta_time;
	while ((finish_time - start_time) < 0.5)
	{
		if (dist < g->tile)
		{
			g->img[P2]->instances[0].x = g->curr.x * g->tile + dist;
			g->img[P2]->instances[0].y = g->curr.y * g->tile + dist;
			dist = (finish_time - start_time) / 0.5 * g->tile;
		}
		finish_time = g->disp.mlx->delta_time;
	}*/
}
