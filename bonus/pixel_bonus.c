/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:00:24 by likong            #+#    #+#             */
/*   Updated: 2024/06/25 10:01:12 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	get_pixel(mlx_image_t *image, uint32_t x, uint32_t y)
{
	uint8_t	*pixelstart;

	if (x > image->width || y > image->height)
		return (0xFF000000);
	pixelstart = image->pixels + (y * image->width + x) * sizeof(int32_t);
	return (get_rgba(*(pixelstart), *(pixelstart + 1), *(pixelstart + 2), *(pixelstart + 3)));
}
