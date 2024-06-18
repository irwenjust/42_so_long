/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:29:44 by likong            #+#    #+#             */
/*   Updated: 2024/06/18 14:19:08 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

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
	//mlx_t	*mlx;
	
	check_args(argc, argv);
	init_game(argv[1]);
	return (EXIT_SUCCESS);
}