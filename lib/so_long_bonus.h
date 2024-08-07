/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:02:04 by likong            #+#    #+#             */
/*   Updated: 2024/07/01 17:52:53 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "header_enum_bonus.h"

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}	t_point;

typedef struct s_map
{
	unsigned int	cols;
	unsigned int	rows;
	unsigned int	starts;
	unsigned int	exits;
	unsigned int	chests;
	unsigned int	enemys;
	unsigned int	players;
	char			**cont;
}	t_map;

typedef struct s_graph
{
	mlx_t	*mlx;
	int		height;
	int		width;
}	t_graph;

typedef struct s_sprite
{
	mlx_image_t	*img;
	uint32_t	rows;
	uint32_t	cols;
}	t_sprite;

typedef struct s_game
{
	t_map			*map;
	t_point			curr;
	t_point			next;
	t_point			exit;
	t_point			*enemy_p;
	t_graph			disp;
	t_state			state;
	t_pstate		p_state;
	mlx_image_t		**img;
	t_sprite		*spr_c;
	t_sprite		*spr_p;
	unsigned int	tile;
	unsigned int	moves;
	unsigned int	coins;
	unsigned int	enemys;
	char			*info;
}	t_game;

//initialize part
void	init_game(char *f_name);

//check map
void	init_map(t_game *g, char *f_name);
void	validate_map(t_game *g);

//draw map
void	draw_map(t_game *g);

//draw image
void	draw_image(t_game *g, t_point p);
void	draw_player(t_game *g, double time);

//hook
void	keyhook(mlx_key_data_t keydata, void *param);
void	closehook(void *param);

//update info
void	update(void *param);

//Initialize player
void	init_player(t_game *g);

//move player
void	move_player(t_game *g);
void	face_enemy(t_game *g);

//tool functions
void	show_error(t_game *game, char *message);
bool	find_path(t_map *map, t_point curr, char **matrix);
t_char	is(t_game *g, t_point p);
bool	is_same_point(t_point p1, t_point p2);
void	check_tile(t_game *g);

//delete part
void	delete_game(t_game *g);
void	del_matrix(char **matrix);

//quit game
void	quit(t_game *g);

//update part
void	update_counter(t_game *g);
void	update_player(t_game *g, double time);
void	update_enemy(t_game *g, double time);

//check player direction
void	check_player_left_right(t_game *g, t_pstate state);
void	check_player_up_down(t_game *g, t_pstate state);

//animation part
void	update_coin(t_game *g, double time);

//pixel part
void	put_pixel(mlx_image_t *img, mlx_image_t *spr, uint32_t x, uint32_t y);

//enemy part
void	check_enemy(t_game *g);

#endif
