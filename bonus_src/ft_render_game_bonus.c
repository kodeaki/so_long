/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_game_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:49:19 by tpirinen          #+#    #+#             */
/*   Updated: 2025/09/01 16:34:57 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong_bonus.h"

int			ft_render_game(t_game *game);
static void	ft_identify_and_render_sprite(t_game *game, int y, int x);
static void	ft_render_player_sprite(t_game *game, int y, int x);
static void	ft_render_sprite(t_game *game, t_image sprite, int y, int x);

/** Renders the game by looping through the map and rendering the sprite
 * that matches that tile based on the game state.
*/
int	ft_render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_identify_and_render_sprite(game, y, x);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
	return (0);
}

/** Identifies the sprite on the given coordinate and renders
 * the appropriate sprite.
 */
static void	ft_identify_and_render_sprite(t_game *game, int y, int x)
{
	char	parameter;

	parameter = game->map.grid[y][x];
	if (parameter == WALL)
		ft_render_sprite (game, game->wall, y, x);
	else if (parameter == FLOOR)
		ft_render_sprite (game, game->floor, y, x);
	else if (parameter == COINS)
		ft_render_sprite (game, game->coins, y, x);
	else if (parameter == EXIT)
	{
		if (game->map.coin_count == 0)
			ft_render_sprite(game, game->exit_open, y, x);
		else
			ft_render_sprite(game, game->exit_closed, y, x);
	}
	else if (parameter == PLAYER)
	{
		ft_render_player_sprite(game, y, x);
	}
}

/** Renders the correct player sprite based on the player orientation.
 */
static void	ft_render_player_sprite(t_game *game, int y, int x)
{
	if (game->player_orientation == LEFT)
		ft_render_sprite(game, game->player_left, y, x);
	if (game->player_orientation == RIGHT)
		ft_render_sprite(game, game->player_right, y, x);
}

/** Uses a minilibx function to render the wanted sprite at the wanted position.
*/
static void	ft_render_sprite(t_game *game, t_image sprite, int y, int x)
{
	mlx_put_image_to_window (
		game->mlx,
		game->window,
		sprite.xpm_ptr,
		x * sprite.x,
		y * sprite.y);
}
