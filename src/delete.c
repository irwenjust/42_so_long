/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:16:45 by likong            #+#    #+#             */
/*   Updated: 2024/06/20 09:52:19 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	delete_image(t_game *g)
{
	int	i;

	i = 0;
	while (i < NUM_IMAGE)
		mlx_delete_image(g->disp.mlx, g->img[i++]);
	free(g->img);
}

void	del_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	delete_map(t_map *map)
{
	if (!map)
		return ;
	del_matrix(map->cont);
	free(map);
}

void	delete_game(t_game *g)
{
	if (!g)
		return ;
	if (g->img)
		delete_image(g);
	if (g->map)
		delete_map(g->map);
	if (g->disp.mlx)
		mlx_terminate(g->disp.mlx);
}
