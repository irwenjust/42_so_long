/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:56:30 by likong            #+#    #+#             */
/*   Updated: 2024/05/31 11:48:12 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

static bool	check_element(t_game *g)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (++y < g->map->rows)
	{
		x = -1;
		while (++x < g->map->cols)
		{
			if (g->map->cont[y][x] == START)
			{
				g->map->players++;
				g->curr = (t_point){x, y};
				g->next = g->curr;
			}
			else if (g->map->cont[y][x] == EXIT)
				g->map->exits++;
			else if (g->map->cont[y][x] == CHEST)
				g->map->chests++;
			else if (!ft_strchr(ELEMENTS, g->map->cont[y][x]))
				return (false);
		}
	}
	return (g->map->players == 1 && g->map->exits == 1 && g->map->chests >= 1);
}

static bool	check_bound(t_map *map)
{
	unsigned int	i;

	i = -1;
	while (++i < map->rows)
		if (map->cont[i][0] != WALL || map->cont[i][map->cols - 1] != WALL)
			return (false);
	i = -1;
	while (++i < map->cols)
		if (map->cont[0][i] != WALL || map->cont[map->rows][i] != WALL)
			return (false);
	return (true);
}

static bool	check_rectangular(t_map *map)
{
	unsigned int	i;
	unsigned int	flen;

	i = 0;
	flen = ft_strlen(map->cont[0]);
	while (i < map->rows)
		if (ft_strlen(map->cont[i++]) != flen)
			return (false);
	map->cols = flen;
	return (true);
}

void	validate_map(t_game *g)
{
	if (g->map->rows == 0)
		show_error(g, "Map is empty.");
	if (!check_rectangular(g->map))
		show_error(g, "Map is not rectangular.");
	if (!check_bound(g->map))
		show_error(g, "Map is not bounded by wall.");
	if (!check_element(g))
		show_error(g, "There has invalid element in map file.");
	if (!check_path(g))
		show_error(g, "Cannot find valid path to collect all chest and go exit.");
}
