/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_enum_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:02:31 by likong            #+#    #+#             */
/*   Updated: 2024/06/19 14:20:50 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_ENUM_BONUS_H
# define HEADER_ENUM_BONUS_H

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

# define ELEMENTS	"01CEPD"

# define BLOCK_SIZE 64

# define NUM_IMAGE 9

typedef enum s_char
{
	SPACE = '0',
	WALL = '1',
	CHEST = 'C',
	EXIT = 'E',
	PLAYER = 'P',
	ENEMY = 'D'
}	t_char;

typedef enum s_image
{
	W1,
	S1,
	C1,
	C2,
	E1,
	E2,
	P1,
	P2,
	D1
}	t_image;

#endif