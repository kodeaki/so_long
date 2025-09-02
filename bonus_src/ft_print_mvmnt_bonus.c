/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mvmnt_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:32:51 by tpirinen          #+#    #+#             */
/*   Updated: 2025/09/02 16:47:52 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong_bonus.h"

/** Draws a white rectangle to the top left of the game window.
 */
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
			if (i < 2 || i >= RECTANGLE_HEIGHT - 2 || j < 2 || j >= RECTANGLE_WIDTH - 2)
				mlx_pixel_put(game->mlx, game->window, x + j, y + i, 0x000000);
			else
				mlx_pixel_put(game->mlx, game->window, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

/** Prints the current movement count inside a white rectangle in the window
 */
void	ft_print_movements(t_game *game)
{
	char	*movement_count;
	char	*counter;

	draw_rect(game, 5, 5, 0x220000);
	movement_count = ft_itoa(game->movement_count);
	counter = ft_strjoin("Movements : ", movement_count);
	mlx_string_put(game->mlx, game->window, 10, 20, 0xFF0000, counter);
	free(movement_count);
	free(counter);
}
