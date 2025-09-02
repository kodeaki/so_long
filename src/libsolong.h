/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsolong.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:44:52 by tpirinen          #+#    #+#             */
/*   Updated: 2025/09/02 16:29:22 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSOLONG_H
# define LIBSOLONG_H

# include "../libraries/libft/libft.h" // for various util functions I've made.
# include "../libraries/minilibx-linux/mlx.h" // for various mlx functions used.

# include <stdbool.h> // for true and false

# include <fcntl.h> // for open()

# include <X11/keysym.h> // for keysym

# include <X11/X.h> // for X11 event and mask definitions

# define IMG_HEIGHT	32
# define IMG_WIDTH	32

# define CATLEFT_XPM "sprites/cat_left.xpm" // player sprite
# define CATRIGHT_XPM "sprites/cat_right.xpm" // player sprite
# define MOUSE_XPM "sprites/mouse.xpm" // coins sprite
// # define WALL_XPM "sprites/wall.xpm" // wall sprite
// # define WALL_XPM "sprites/Brick_wall.xpm" // wall sprite
# define WALL_XPM "sprites/brick_wall_cracked.xpm" // wall sprite
# define FLOOR_XPM "sprites/rocky_road.xpm" // floor sprite
# define EXIT_OPEN_XPM "sprites/hell.xpm" // exit sprite
# define EXIT_CLOSED_XPM "sprites/hell_locked.xpm" // exit sprite

# define WALL			'1'
# define FLOOR 			'0'
# define COINS  		'C'
# define PLAYER			'P'
# define EXIT 		 	'E'
# define FLOODFILL_MARK	'X'

# define LEFT 			0
# define RIGHT 			1

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char	**grid;
	char	**floodfill;
	int		rows;
	int		columns;
	int		player_count;
	int		coin_count;
	int		exit_count;
	int		player_row;
	int		player_column;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_map	map;
	int		player_orientation;
	t_image	player_left;
	t_image	player_right;
	t_image	wall;
	t_image	floor;
	t_image	coins;
	t_image	exit_open;
	t_image	exit_closed;
	int		movement_count;
}	t_game;

int		ft_handle_input(int keysym, t_game *game);

void	ft_validate_args(int ac, char **av, t_game *game);

void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);

void	ft_init_map(t_game *game, char *map_filename);
void	ft_parse_map(t_game *game);
void	ft_check_valid_path_to_win(t_game *game);

int		ft_render_game(t_game *game);

void	ft_free_all(t_game *game);
int		ft_close_game(t_game *game);
void	ft_err_msg_exit(char *msg, t_game *game);

#endif
