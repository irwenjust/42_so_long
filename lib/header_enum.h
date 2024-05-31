/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_enum.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:50:44 by likong            #+#    #+#             */
/*   Updated: 2024/05/31 11:33:45 by likong           ###   ########.fr       */
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

typedef enum s_charactor
{
	SPACE = '0',
	WALL = '1',
	CHEST = 'C',
	EXIT = 'E',
	START = 'P'
}	t_charactor;

#endif
