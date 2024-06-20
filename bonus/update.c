/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:43:17 by likong            #+#    #+#             */
/*   Updated: 2024/06/20 17:11:52 by likong           ###   ########.fr       */
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
