/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:12:11 by likong            #+#    #+#             */
/*   Updated: 2024/05/31 11:32:33 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "header_enum.h"

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}	t_point;


typedef struct	s_map
{
	unsigned int	cols;
	unsigned int	rows;
	unsigned int	starts;
	unsigned int	exits;
	unsigned int	chests;
	unsigned int	players;
	char			**cont;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	t_point	curr;
	t_point	next;
}	t_game;

//initialize part
void	init_game(char *f_name);

//check map
void	init_map(t_game *g, char *f_name);
//int	map_check(t_game *game, char *f_name);

//tool functions
void show_error(t_game *game, char *message);

#endif
