/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:29:44 by likong            #+#    #+#             */
/*   Updated: 2024/06/21 17:29:53 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"

void	quit(t_game *g)
{
	delete_game(g);
	exit(EXIT_SUCCESS);
}

static void	check_args(int argc, char **argv)
{
	(void)argv;
	if (argc <= 1)
	{
		ft_printf("please choice one *.ber map with so_long.\n");
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		ft_printf("Only need one map with so_long, pleae check again.\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	init_game(argv[1]);
	return (EXIT_SUCCESS);
}

/*
// Function to create a delay
void delay(double seconds) {
    double start_time = mlx_get_time(); // Get the current time
	printf("%lf\n", start_time);
    while (mlx_get_time() < start_time + seconds) {
        // Busy-wait loop until the desired time has passed
    }
}

int main() {
    mlx_t* mlx = mlx_init(800, 600, "MLX42 Window", true);
    if (!mlx) {
        fprintf(stderr, "Failed to initialize MLX42\n");
        return 1;
    }

    // Main loop
    while (!mlx_is_key_down(mlx, MLX_KEY_ESCAPE)) {
        mlx_close_window(mlx);
        
        // Your drawing code here
        printf("wow\n");
        
        delay(1.0); // Delay for 1 second
    }

    mlx_terminate(mlx);
    return 0;
}

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static int32_t	get_pixel(mlx_image_t *image, uint32_t x, uint32_t y)
{
	uint8_t	*pixelstart;

	if (x > image->width || y > image->height)
		return (0xFF000000);
	pixelstart = image->pixels + (y * image->width + x) * sizeof(int32_t);
	return (get_rgba(\
		*(pixelstart), \
		*(pixelstart + 1), \
		*(pixelstart + 2), \
		*(pixelstart + 3) \
	));
}

int main(void)
{
    mlx_t *mlx = mlx_init(800, 600, "MLX42 Window", true);

    mlx_set_setting(MLX_STRETCH_IMAGE, 1);
    mlx_image_t *img = mlx_texture_to_image(mlx, mlx_load_png("./assets/chest/coin.png"));
    uint32_t i;
    uint32_t j;
    //mlx_image_to_window(mlx, img, 0, 0);
    mlx_image_t *new = mlx_new_image(mlx, 16, 16);
    ft_memset(new->pixels, 255, new->width * new->height * sizeof(int32_t));
    //printf("width: %u, height:%u\n", img->width, img->height);
    uint32_t k = 0;
    while (k < 12)
    {
        i = 0;
        while (i < new->width)
        {
            j = 0;
            while (j < new->height)
            {
                mlx_put_pixel(new, i, j, get_pixel(img, i + k * 16, j));
                //ft_printf("wow\n");
                j++;
            }
            i++;
        }
        mlx_image_to_window(mlx, new, k * 16, 0);

        usleep(100000);
        k++;
    }
    
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (0);
}

*/
