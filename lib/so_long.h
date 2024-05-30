/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:12:11 by likong            #+#    #+#             */
/*   Updated: 2024/05/30 22:13:03 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include "../libft/get_next_line/get_next_line.h"

typedef struct	s_map
{
	unsigned int	cols;
	unsigned int	rows;
	unsigned int	starts;
	unsigned int	exits;
	unsigned int	players;
	char			*f_name;
	char			**cont;
}	t_map;

typedef struct s_game
{
	t_map	*map;
}	t_game;

//initialize part
int	init_game(char *f_name);

//check map
int	map_check(t_game *game, char *f_name);

//tool functions
void show_error(t_game *game, char *message);

#endif


