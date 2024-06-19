/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:09:12 by likong            #+#    #+#             */
/*   Updated: 2024/06/19 14:51:47 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

t_char	is(t_game *g, t_point p)
{
	return (g->map->cont[p.y][p.x]);
}

bool	is_same_point(t_point p1, t_point p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}

void	record_exit(t_game *g, t_point p)
{
	g->exit.x = p.x;
	g->exit.y = p.y;
}

bool	find_path(t_map *map, t_point curr, char **matrix)
{
	static unsigned int	chests = 0;
	static bool			find_exit = false;

	if (matrix[curr.y][curr.x] == WALL || matrix[curr.y][curr.x] == ENEMY)
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

void	show_error(t_game *g, char *message)
{
	delete_game(g);
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}
