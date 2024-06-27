/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:43:17 by likong            #+#    #+#             */
/*   Updated: 2024/06/27 12:42:37 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

void	update_enemy(t_game *g)
{
	(void)g;
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

	local_time += time;
	if (current >= 12)
		current = 0;
	if (local_time > 0.08)
	{
		put_pixel(g->img[C1], g->spr_c->img, current, 0);
		current++;
		local_time -= 0.08;
	}
}

void	update_player(t_game *g, double time)
{
	static unsigned int	dist = 0;
	t_image				img;

	img = PU;
	if (g->p_state != STOP && dist >= g->tile)
	{
		g->p_state = STOP;
		g->curr = g->next;
		dist = 0;
	}
	else if (g->p_state != STOP && dist < g->tile)
	{
		draw_player(g, time);
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
