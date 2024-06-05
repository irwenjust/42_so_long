/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:09:12 by likong            #+#    #+#             */
/*   Updated: 2024/06/05 10:47:25 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

bool	find_path(t_map *map, t_point curr, char **matrix)
{
	static unsigned int	chests = 0;
	static bool			find_exit = false;

	if (matrix[curr.y][curr.x] == WALL)
		return (false);
	else if (matrix[curr.y][curr.x] == CHEST)
		chests++;
	else if (matrix[curr.y][curr.x] == EXIT)
		find_exit = true;
	matrix[curr.y][curr.x] = WALL;
	find_path(map, (t_point){curr.x + 1, curr.y}, matrix);
	find_path(map, (t_point){curr.x - 1, curr.y}, matrix);
	find_path(map, (t_point){curr.x, curr.y + 1}, matrix);
	find_path(map, (t_point){curr.x, curr.y - 1}, matrix);
	return (chests == map->chests && find_exit);
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

void	show_error(t_game *g, char *message)
{
	delete_game(g);
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}
