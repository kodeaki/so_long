/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mvmnt_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:32:51 by tpirinen          #+#    #+#             */
/*   Updated: 2025/08/29 14:19:48 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong_bonus.h"

void	draw_rect(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 90)
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

	draw_rect(game, 35, 10, 0x000000);
	movement_count = ft_itoa(game->movement_count);
	counter = ft_strjoin("Movements : ", movement_count);
	mlx_string_put(game->mlx, game->window, 40, 20, 0xFFFFFF, counter);
	free(movement_count);
	free(counter);
}
