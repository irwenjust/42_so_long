/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:09:12 by likong            #+#    #+#             */
/*   Updated: 2024/05/30 22:12:02 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	show_error(t_game *g, char *message)
{
	(void)g;
	ft_printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}
