/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:49:19 by tpirinen          #+#    #+#             */
/*   Updated: 2025/08/28 22:52:32 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsolong.h"

int			ft_render_map(t_game *game);
static void	ft_identify_sprite(t_game *game, int y, int x);
static void	ft_render_player_sprite(t_game *game, int y, int x);
static void	ft_render_sprite(
				t_game *game, t_image sprite, int line, int column);
static void	ft_print_movements(t_game *game);

int	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_identify_sprite(game, y, x);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
	return (0);
}

static void	ft_identify_sprite(t_game *game, int y, int x)
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

static void	ft_render_player_sprite(t_game *game, int y, int x)
{
	if (game->player_orientation == LEFT)
		ft_render_sprite(game, game->player_left, y, x);
	if (game->player_orientation == RIGHT)
		ft_render_sprite(game, game->player_right, y, x);
}

static void	ft_render_sprite(t_game *game, t_image sprite, int y, int x)
{
	mlx_put_image_to_window (
		game->mlx,
		game->window,
		sprite.xpm_ptr,
		x * sprite.x,
		y * sprite.y);
}

// Draw a solid rectangle as background for the text
void draw_rect(t_game *game, int x, int y, int w, int h, int color)
{
    int	i;
	int	j;
	
	i = 0;
    while (i < h)
	{
		j = 0;
        while (j < w)
		{
            mlx_pixel_put(game->mlx, game->window, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

static void	ft_print_movements(t_game *game)
{
    char	*movement_count;
    char	*counter;

    // Draw background rectangle (e.g., black)
    draw_rect(game, 35, 10, 90, 20, 0x000000);

    movement_count = ft_itoa(game->movement_count);
    counter = ft_strjoin("Movements : ", movement_count);
    // Draw text in white
    mlx_string_put(game->mlx, game->window, 40, 20, 0xFFFFFF, counter);
    free(movement_count);
    free(counter);
}