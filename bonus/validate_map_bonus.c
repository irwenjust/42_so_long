/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:56:30 by likong            #+#    #+#             */
/*   Updated: 2024/07/01 17:55:28 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

static bool	check_path(t_game *g)
{
	char			**dup;
	bool			is_valid;
	unsigned int	i;

	i = 0;
	dup = ft_calloc(g->map->rows + 1, sizeof(char *));
	if (!dup)
		show_error(g, "Allocation error on check_path.");
	while (i < g->map->rows)
	{
		dup[i] = ft_strdup(g->map->cont[i]);
		if (!dup[i])
		{
			del_matrix(dup);
			show_error(g, "Allocation error on check_path.");
		}
		i++;
	}
	is_valid = find_path(g->map, g->curr, dup);
	del_matrix(dup);
	return (is_valid);
}

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
			if (g->map->cont[y][x] == PLAYER)
			{
				g->map->players++;
				g->curr = (t_point){x, y};
			}
			else if (g->map->cont[y][x] == EXIT)
				g->map->exits++;
			else if (g->map->cont[y][x] == CHEST)
				g->map->chests++;
			else if (g->map->cont[y][x] == ENEMY)
				g->map->enemys++;
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
		if (map->cont[0][i] != WALL || map->cont[map->rows - 1][i] != WALL)
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
		show_error(g, "Map elements has some of mistake.");
	if (!check_path(g))
		show_error(g, "Cannot find valid path to collect and go exit.");
	g->next = g->curr;
}
