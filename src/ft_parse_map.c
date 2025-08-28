/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:18:43 by tpirinen          #+#    #+#             */
/*   Updated: 2025/08/28 23:25:43 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsolong.h"

void		ft_parse_map(t_game *game);
static void	ft_count_parameters(t_game *game);
static void	ft_verify_parameter_count(t_game *game);

void	ft_parse_map(t_game *game)
{
	ft_count_parameters(game);
	ft_verify_parameter_count(game);
}

static void	ft_count_parameters(t_game *game)
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
				ft_err_msg_exit("Error\n"
					"Invalid Map. Unexpected parameter.", game);
			if (game->map.grid[y][x] == PLAYER)
			{
				game->map.player_count++;
				game->map.player_position_x = x;
				game->map.player_position_y = y;
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

static void	ft_verify_parameter_count(t_game *game)
{
	int	error;

	error = false;
	if (game->map.player_count != 1)
	{
		error = true;
		write(2, "Error\nInvalid Map. "
			"There must be one player, no more, no less.\n", 63);
	}
	if (game->map.exit_count != 1)
	{
		error = true;
		write(2, "Error\nInvalid Map. "
			"There must be one exit, no more, no less.\n", 62);
	}
	if (game->map.coin_count == 0)
	{
		error = true;
		write(2, "Error\nInvalid Map. Where the coins at?\n", 39);
	}
	if (error == true)
		ft_err_msg_exit("", game);
}
