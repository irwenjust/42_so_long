/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:30:08 by likong            #+#    #+#             */
/*   Updated: 2024/05/30 22:21:04 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

static t_map	*map_new(unsigned int cols, unsigned int rows)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->cont = ft_calloc(rows + 1, sizeof(char *));
	if (!map->cont)
	{
		free(map);
		return (NULL);
	}
	map->cols = cols;
	map->rows = rows;
	return (map);
}

static int	get_rows(t_game *g, char *f_name)
{
	int		fd;
	int		rows;
	char	*res;

	rows = 0;
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		show_error(g, "Cannot open requested file.");
	while (1)
	{
		res = get_next_line(fd);
		if (!res)
			break ;
		rows++;
		free(res);
	}
	close(fd);
	return (rows);
}

int	init_map(t_game *g, char *f_name)
{
	int		fd;
	int		i;
	char	*res;

	i = 0;
	g->map = map_new(0, get_rows(g, f_name));
	if (!g->map)
		show_error(g, "Allocation error on map.");
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		show_error(g, "Cannot open requested file.");
	while (i < g->map->rows)
	{
		res = get_next_line(fd);
		if (!res)
			show_error(g, "Allocation error on map column.");
		g->map->cont[i] = ft_strtrim(res, "\n");
		if (!g->map->cont[i])
			show_error(g, "Error on map column when delete new line sign.");
		free(res);
	}
	close(fd);
}