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
		ft_printf("Only need one map with so_long, pleae chec11 again.\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	init_game(argv[1]);
	return (EXIT_SUCCESS);
}

/*int main(void)
{
    mlx_t *mlx = mlx_init(800, 600, "MLX42 Window", true);

    mlx_set_setting(MLX_STRETCH_IMAGE, 1);
    mlx_image_t *sprite = mlx_texture_to_image(mlx, mlx_load_png("./assets/chest/coin.png"));
    mlx_resize_image(sprite, 16 * 12 * 4, 16 * 4);
    mlx_image_t *img = mlx_new_image(mlx, 64, 64);
    //printf("width: %u, height:%u\n", img->width, img->height);
   	t_test test;
	test.sprite = sprite;
	test.count = 12;
	test.img = img;
	test.mlx = mlx;
	//mlx_image_to_window(test.mlx, test.img, 1 * 64, 0);
	//mlx_image_to_window(test.mlx, img, 0, 0);
	mlx_image_to_window(test.mlx, test.img, 0, 0);
   	mlx_loop_hook(mlx, coin_animation, &test);
    
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (0);
}*/


