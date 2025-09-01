/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:45:28 by tpirinen          #+#    #+#             */
/*   Updated: 2025/09/01 14:55:38 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong.h"

int			ft_handle_input(int keysym, t_game *game);
int			ft_close_game(t_game *game);
static void	ft_move_player(t_game *game, int y_new, int x_new, int orientation);
static int	ft_win(t_game *game);

/** Handles keyboard input events for the game window.
 *
 * @param keysym The key symbol (keycode) of the pressed key provided by MLX.
 * @param game   Pointer to the t_game struct.
 *
 * If the Escape key is pressed, this function will free all allocated memory
 * and exit the program. For any other key, it prints the keycode to stdout.
 *
 * @return Returns 0 unless ESC is pressed, in which case exits.
 */
int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == XK_w)
		ft_move_player(game,
			game->map.player_row - 1, game->map.player_column,
			game->player_orientation);
	if (keysym == XK_a)
		ft_move_player(game,
			game->map.player_row, game->map.player_column - 1,
			LEFT);
	if (keysym == XK_s)
		ft_move_player(game,
			game->map.player_row + 1, game->map.player_column,
			game->player_orientation);
	if (keysym == XK_d)
		ft_move_player(game,
			game->map.player_row, game->map.player_column + 1,
			RIGHT);
	if (keysym == XK_Escape)
		ft_close_game(game);
	return (0);
}

/** Moves the player and completes the expected operations based on the
 * position that the player is being moved into.
 */
static void	ft_move_player(t_game *game, int y_new, int x_new, int orientation)
{
	int	y_before;
	int	x_before;

	game->player_orientation = orientation;
	y_before = game->map.player_row;
	x_before = game->map.player_column;
	if (game->map.grid[y_new][x_new] == EXIT && game->map.coin_count == 0)
		ft_win(game);
	else if ((game->map.grid[y_new][x_new] == FLOOR)
		|| (game->map.grid[y_new][x_new] == COINS))
	{
		game->movement_count++;
		ft_printf("Movement count: %d\n\n", game->movement_count);
		if (game->map.grid[y_new][x_new] == COINS)
			game->map.coin_count--;
		game->map.grid[y_before][x_before] = FLOOR;
		game->map.grid[y_new][x_new] = PLAYER;
		game->map.player_column = x_new;
		game->map.player_row = y_new;
		ft_render_game(game);
	}
}

/** Closes the game cleanly with an "esc was pressed" message.
 * Used when escape or the X in the corner of the window is pressed.
 */
int	ft_close_game(t_game *game)
{
	ft_printf("Game closed!\n");
	ft_free_all(game);
	exit(0);
}

/** Closes the game cleanly with a message declaring "YOU WIN!"
 */
static int	ft_win(t_game *game)
{
	ft_printf("\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
Total movement count: %d\n\n", ++game->movement_count);
	ft_free_all(game);
	exit(0);
}
