/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_path_to_win_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:35:38 by tpirinen          #+#    #+#             */
/*   Updated: 2025/08/29 18:25:10 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong_bonus.h"

void		ft_check_valid_path_to_win(t_game *game);
static void	ft_flood_fill(t_game *game, int row, int column);

void	ft_check_valid_path_to_win(t_game *game)
{
	int	y;
	int	x;

	ft_flood_fill(game, game->map.player_row, game->map.player_column);
	y = 0;
	while (game->map.floodfill[y])
	{
		x = 0;
		while (game->map.floodfill[y][x])
		{
			if (game->map.floodfill[y][x] == COINS
			|| game->map.floodfill[y][x] == EXIT)
				ft_err_msg_exit("Coin or exit out of reach.", game);
			x++;
		}
		y++;
	}
}

static void	ft_flood_fill(t_game *game, int row, int column)
{
	if (game->map.floodfill[row][column] == WALL
	|| game->map.floodfill[row][column] == FLOODFILL_MARK)
		return ;
	game->map.floodfill[row][column] = FLOODFILL_MARK;
	ft_flood_fill(game, row, column - 1);
	ft_flood_fill(game, row, column + 1);
	ft_flood_fill(game, row - 1, column);
	ft_flood_fill(game, row + 1, column);
}
