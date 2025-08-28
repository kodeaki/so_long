/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:16:26 by tpirinen          #+#    #+#             */
/*   Updated: 2025/08/28 22:21:42 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsolong.h"

static t_image	ft_new_sprite(void *mlx, char *path, t_game *game);

/** Initiates all the sprites needed by the game.
 * 
 * @param game Pointer to the game struct.
 */
void	ft_init_sprites(t_game *game)
{
	game->player_left = ft_new_sprite(game->mlx, CATLEFT_XPM, game);
	game->player_right = ft_new_sprite(game->mlx, CATRIGHT_XPM, game);
	game->coins = ft_new_sprite(game->mlx, MOUSE_XPM, game);
	game->wall = ft_new_sprite(game->mlx, WALL_XPM, game);
	game->floor = ft_new_sprite(game->mlx, FLOOR_XPM, game);
	game->exit_open = ft_new_sprite(game->mlx, EXIT_OPEN_XPM, game);
	game->exit_closed = ft_new_sprite(game->mlx, EXIT_CLOSED_XPM, game);
}

/** Initiates a sprite given by the path
 * 
 * @param mlx Pointer to the mlx
 * @param path Path to the sprite
 * @param game Pointer to the game struct.
 */
static t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
	{
		ft_err_msg_exit("Error\nSprite not found.\n", game);
		exit(1);
	}
	return (sprite);
}
