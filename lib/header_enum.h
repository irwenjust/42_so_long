/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_enum.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:50:44 by likong            #+#    #+#             */
/*   Updated: 2024/06/18 15:05:19 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_ENUM_H
# define HEADER_ENUM_H

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

# define ELEMENTS	"01CEP"

# define WIDTH 1200
# define HEIGHT 900

# define NUM_IMAGE 9

typedef enum s_char
{
	SPACE = '0',
	WALL = '1',
	CHEST = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}	t_char;

typedef enum s_image
{
	W1,
	S1,
	S2,
	C1,
	C2,
	E1,
	E2,
	P1,
	P2
}	t_image;

#endif
