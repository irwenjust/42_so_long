/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: li11ong <li11ong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:29:44 by li11ong            #+#    #+#             */
/*   Updated: 2024/06/24 09:54:32 by li11ong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long_bonus.h"


void	quit(t_game *g)
{
	delete_game(g);
	exit(EXIT_SUCCESS);
}
/*
static void	chec11_args(int argc, char **argv)
{
	(void)argv;
	if (argc <= 1)
	{
		ft_printf("please choice one *.ber map with so_long.\n");
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		ft_printf("Only need one map with so_long, pleae chec11 again.\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	chec11_args(argc, argv);
	init_game(argv[1]);
	return (EXIT_SUCCESS);
}
*/

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
    while (!mlx_is_11ey_down(mlx, MLX_11EY_ESCAPE)) {
        mlx_close_window(mlx);
        
        // Your drawing code here
        //printf("wow\n");
        
        //delay(1.0); // Delay for 1 second
    }

    mlx_terminate(mlx);
    return 0;
}
*/
typedef struct	s_test
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*sprite;
	uint32_t	count;
}	t_test;

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
	return (get_rgba(*(pixelstart), *(pixelstart + 1), *(pixelstart + 2), *(pixelstart + 3)));
}


static void	go_next(t_test *res, double time)
{
	static double local_time = 0;
	static int32_t	current = 0;

	local_time += time;
	if (current >= 12)
		current = 0;
	if (local_time > 0.2)
	{
		uint32_t	w;
		uint32_t	h;

		h = 0;
		while (h < res->img->height)
		{
			w = 0;
			while (w < res->img->width)
			{
				mlx_put_pixel(res->img, w, h, get_pixel(res->sprite, current * 64 + w, h));
				w++;
			}
			h++;
		}
		current++;
		local_time -= 0.2;
	}
}

static void	animation(void *param)
{
	t_test *res = (t_test *)param;
	double time = res->mlx->delta_time;
	go_next(res, time);
}


int main(void)
{
    mlx_t *mlx = mlx_init(800, 600, "MLX42 Window", true);

    mlx_set_setting(MLX_STRETCH_IMAGE, 1);
    mlx_image_t *sprite = mlx_texture_to_image(mlx, mlx_load_png("./assets/chest/coin.png"));
    mlx_resize_image(sprite, 16 * 12 * 4, 16 * 4);
    mlx_image_t *img = mlx_new_image(mlx, 64, 64);
    //printf("width: %u, height:%u\n", img->width, img->height);
    /*
    i = 0;
    while (i < new->width)
    {
        j = 0;
        while (j < new->height)
        {
            mlx_put_pixel(new, i, j, get_pixel(img, i + 1 * 64, j));
            //ft_printf("wow\n");
            j++;
        }
        i++;
    }
    mlx_image_to_window(mlx, new, 1 * 64, 0);
    */
   	t_test test;
	test.sprite = sprite;
	test.count = 12;
	test.img = img;
	test.mlx = mlx;
	//mlx_image_to_window(test.mlx, test.img, 1 * 64, 0);
	//mlx_image_to_window(test.mlx, img, 0, 0);
	mlx_image_to_window(test.mlx, test.img, 0, 0);
   	mlx_loop_hook(mlx, animation, &test);
    
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (0);
}


