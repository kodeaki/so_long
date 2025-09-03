/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mvmnt_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:32:51 by tpirinen          #+#    #+#             */
/*   Updated: 2025/09/03 14:48:08 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong_bonus.h"

/** Draws a rectangle to the top left of the game window.
 */
static void	draw_rectangle(t_game *game, int x, int y, int color)
{
	int		i;
	int		j;
	int		height;
	int		width;
	char	*movement_count_str;

	height = 20;
	width = 165;
	movement_count_str = ft_itoa(game->movement_count);
	width += 6 * ft_strlen(movement_count_str);
	free(movement_count_str);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i < 2 || i >= height - 2 || j < 2 || j >= width - 2)
				mlx_pixel_put(game->mlx, game->window, x + j, y + i, 0x000000);
			else
				mlx_pixel_put(game->mlx, game->window, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

/** Prints the current movement count inside a rectangle in the window
 */
void	ft_print_movements(t_game *game)
{
	char	*movement_count;
	char	*counter;

	draw_rectangle(game, 5, 5, 0x220000);
	movement_count = ft_itoa(game->movement_count);
	counter = ft_strjoin("Steps taken towards hell: ", movement_count);
	mlx_string_put(game->mlx, game->window, 10, 20, 0xFF0000, counter);
	free(movement_count);
	free(counter);
}
