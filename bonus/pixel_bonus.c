/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:00:24 by likong            #+#    #+#             */
/*   Updated: 2024/06/27 11:14:53 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static int32_t	get_pixel(mlx_image_t *image, uint32_t x, uint32_t y)
{
	uint8_t	*start;

	if (x > image->width || y > image->height)
		return (0xFF000000);
	start = image->pixels + (y * image->width + x) * sizeof(int32_t);
	return (get_rgba(*(start),
			*(start + 1),
			*(start + 2),
			*(start + 3)));
}

void	put_pixel(mlx_image_t *img, mlx_image_t *spr, uint32_t x, uint32_t y)
{
	uint32_t		w;
	uint32_t		h;

	h = 0;
	while (h < img->height)
	{
		w = 0;
		while (w < img->width)
		{
			mlx_put_pixel(img, w, h,
				get_pixel(spr, x * 64 + w, y * 64 + h));
			w++;
		}
		h++;
	}
}
