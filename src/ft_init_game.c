/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:08:19 by tpirinen          #+#    #+#             */
/*   Updated: 2025/08/28 22:19:30 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsolong.h"

/** Initiates a connection to minilibx and opens a window.
 * 
 * @param game Pointer to the game struct.
 */
void	ft_init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_err_msg_exit("Error\nFailed to initiate mlx.\n", game);
	game->window = mlx_new_window(
			game->mlx,
			game->map.columns * IMG_WIDTH,
			game->map.rows * IMG_HEIGHT,
			"so_long");
	if (game->window == NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
}
