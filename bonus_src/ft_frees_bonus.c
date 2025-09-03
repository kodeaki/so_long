/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:56:00 by tpirinen          #+#    #+#             */
/*   Updated: 2025/09/03 18:12:26 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong_bonus.h"

void		ft_free_all(t_game *game);
static void	ft_destroy_images(t_game *game);
static void	ft_free_maps(t_game *game);

/** Cleans up all allocated memory, closes the window and closes the
 * connection to minilibx.
 */
void	ft_free_all(t_game *game)
{
	ft_destroy_images(game);
	ft_free_maps(game);
	if (game->mlx)
	{
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map_fd)
		close(game->map_fd);
}

/** Destroys the sprite images initiated with minilibx.
 */
static void	ft_destroy_images(t_game *game)
{
	if (game->player_left.xpm_ptr)
		mlx_destroy_image(game->mlx, game->player_left.xpm_ptr);
	if (game->player_right.xpm_ptr)
		mlx_destroy_image(game->mlx, game->player_right.xpm_ptr);
	if (game->wall.xpm_ptr)
		mlx_destroy_image(game->mlx, game->wall.xpm_ptr);
	if (game->floor.xpm_ptr)
		mlx_destroy_image(game->mlx, game->floor.xpm_ptr);
	if (game->coins.xpm_ptr)
		mlx_destroy_image(game->mlx, game->coins.xpm_ptr);
	if (game->exit_open.xpm_ptr)
		mlx_destroy_image(game->mlx, game->exit_open.xpm_ptr);
	if (game->exit_closed.xpm_ptr)
		mlx_destroy_image(game->mlx, game->exit_closed.xpm_ptr);
}

/** Frees both map arrays in the game struct
 */
static void	ft_free_maps(t_game *game)
{
	int	i;

	if (game->map.grid)
	{
		i = 0;
		while (i < game->map.rows)
			free(game->map.grid[i++]);
		free(game->map.grid);
	}
	if (game->map.floodfill)
	{
		i = 0;
		while (i < game->map.rows)
			free(game->map.floodfill[i++]);
		free(game->map.floodfill);
	}
}
