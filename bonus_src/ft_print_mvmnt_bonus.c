/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mvmnt_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:32:51 by tpirinen          #+#    #+#             */
/*   Updated: 2025/09/01 14:09:26 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong_bonus.h"

static void	draw_rect(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < RECTANGLE_HEIGHT)
	{
		j = 0;
		while (j < RECTANGLE_WIDTH)
		{
			mlx_pixel_put(game->mlx, game->window, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	ft_print_movements(t_game *game)
{
	char	*movement_count;
	char	*counter;

	draw_rect(game, 33, 6, 0xFFFFFF);
	movement_count = ft_itoa(game->movement_count);
	counter = ft_strjoin("Movements : ", movement_count);
	mlx_string_put(game->mlx, game->window, 40, 20, 0x000000, counter);
	free(movement_count);
	free(counter);
}
