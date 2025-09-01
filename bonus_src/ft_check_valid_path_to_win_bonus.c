/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_path_to_win_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:35:38 by tpirinen          #+#    #+#             */
/*   Updated: 2025/09/01 16:40:15 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong_bonus.h"

void		ft_check_valid_path_to_win(t_game *game);
static void	ft_flood_fill(t_game *game, int row, int column);

/** Makes sure that all coins and the exit are reachable by the player.
 * ft_flood_fill() will mark over all coin and exit characters that are
 * reachable by the player, so if any coins or an exit are found afterwards
 * they are unreachable and the game will not start.
 */
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

/** Floodfill algorithm, Starts from the players position and moves recursively
 * up, down, left and right marking the position. If the current position is
 * a wall, exit or previously marked position the recursion of that path ends.
 * Players can't step into a closed exit but they also need to be marked as
 * reachable, which is why the exit gets marked and then returns.
 * 
 * @param row the current row in the recursion
 * @param column the current column in the recursion
 */
static void	ft_flood_fill(t_game *game, int row, int column)
{
	if (game->map.floodfill[row][column] == EXIT)
	{
		game->map.floodfill[row][column] = FLOODFILL_MARK;
		return ;
	}
	if (game->map.floodfill[row][column] == WALL
	|| game->map.floodfill[row][column] == FLOODFILL_MARK)
		return ;
	game->map.floodfill[row][column] = FLOODFILL_MARK;
	ft_flood_fill(game, row, column - 1);
	ft_flood_fill(game, row, column + 1);
	ft_flood_fill(game, row - 1, column);
	ft_flood_fill(game, row + 1, column);
}
