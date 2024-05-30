/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:29:44 by likong            #+#    #+#             */
/*   Updated: 2024/05/30 22:14:13 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"
#define WIDTH 512
#define HEIGHT 512

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
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
	mlx_t	*mlx;
	
	check_args(argc, argv);
	init_game(argv[1]);
	mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
        error();
	// Try to load the file
	mlx_texture_t* texture = mlx_load_png("./temp/coin.png");
	if (!texture)
        error();
	
	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
        error();

	// Display the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();

	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}