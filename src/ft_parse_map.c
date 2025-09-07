/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:18:43 by tpirinen          #+#    #+#             */
/*   Updated: 2025/09/07 13:16:22 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong.h"

void		ft_parse_map(t_game *game);
static void	ft_count_map_parameters(t_game *game);
static void	ft_verify_map_parameter_count(t_game *game);
static void	ft_check_is_map_rectangular(t_game *game);
static void	ft_check_is_map_enclosed(t_game *game);

/** Parses the map to make sure it's valid before starting the game.
 * Uses static functions from this file to check for basic invalidities
 * and finishes with a floodfill algorithm to check if there's a
 * valid path to win the game.
 */
void	ft_parse_map(t_game *game)
{
	ft_check_is_map_rectangular(game);
	ft_check_is_map_enclosed(game);
	ft_count_map_parameters(game);
	ft_verify_map_parameter_count(game);
	ft_check_valid_path_to_win(game);
}

/** Counts the parameters in the map.
 */
static void	ft_count_map_parameters(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("PC01E", game->map.grid[y][x]))
				ft_err_msg_exit("Unexpected parameter. Use: PC01E", game);
			if (game->map.grid[y][x] == PLAYER)
			{
				game->map.player_count++;
				game->map.player_column = x;
				game->map.player_row = y;
			}
			else if (game->map.grid[y][x] == COINS)
				game->map.coin_count++;
			else if (game->map.grid[y][x] == EXIT)
				game->map.exit_count++;
			x++;
		}
		y++;
	}
}

/** Checks that the map has a valid count of parameters.
 */
static void	ft_verify_map_parameter_count(t_game *game)
{
	if (game->map.player_count != 1
		|| game->map.exit_count != 1
		|| game->map.coin_count == 0)
	{
		ft_putendl_fd("Error", 1);
		if (game->map.player_count != 1)
			ft_putendl_fd("Invalid Map. "
				"There must be one player, no more, no less.", 1);
		if (game->map.exit_count != 1)
		{
			ft_putendl_fd("Invalid Map. "
				"There must be one exit, no more, no less.", 1);
		}
		if (game->map.coin_count == 0)
		{
			ft_putendl_fd("Invalid Map. Where the coins at?", 1);
		}
		ft_free_all(game);
		exit(1);
	}
}

/** Checks that the map is rectangular by comparing every row's length
 * with the length of the first row.
 */
static void	ft_check_is_map_rectangular(t_game *game)
{
	size_t	row_length;
	int		i;

	row_length = ft_strlen(game->map.grid[0]);
	i = 0;
	while (game->map.grid[i])
	{
		if (row_length != ft_strlen(game->map.grid[i]))
			ft_err_msg_exit("Map must be rectangular.", game);
		i++;
	}
}

/** Check that the map is fully enclosed by walls by iterating through the
 * map and on the edges checking if the character is something other than '1'
 */
static void	ft_check_is_map_enclosed(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if ((y == 0 || y == game->map.rows - 1)
				|| (x == 0 || x == game->map.columns - 1))
				if (game->map.grid[y][x] != WALL)
					ft_err_msg_exit("Map is not enclosed", game);
			x++;
		}
		y++;
	}
}
