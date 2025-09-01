/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:10:06 by tpirinen          #+#    #+#             */
/*   Updated: 2025/09/01 14:07:41 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong_bonus.h"

void		ft_init_map(t_game *game, char *map_filename);
static char	*ft_append_line_to_map(char *new_map, char *line, t_game *game);
static void	empty_line_check(char *new_map, t_game *game);

/** Initiates the the map struct inside of the game struct 
 * from the .ber map file.
 * 
 * @param game Pointer to the game struct.
 * @param map_filename Filename from the first command line arguments argv[1].
 * 
 * Counts the number of rows in the map file and gets the number of columns
 * with ft_strlen()
 */
void	ft_init_map(t_game *game, char *map_filename)
{
	char	*new_map;
	char	*line;
	int		map_fd;

	map_fd = open(map_filename, O_RDONLY);
	if (map_fd == -1)
		ft_err_msg_exit("Couldn't open map file..?\n", game);
	new_map = ft_strdup("");
	line = get_next_line(map_fd);
	if (line == NULL)
		ft_err_msg_exit("Map file is empty", game);
	while (line != NULL)
	{
		new_map = ft_append_line_to_map(new_map, line, game);
		free(line);
		game->map.rows++;
		line = get_next_line(map_fd);
	}
	free(line);
	empty_line_check(new_map, game);
	game->map.grid = ft_split(new_map, '\n');
	game->map.floodfill = ft_split(new_map, '\n');
	game->map.columns = ft_strlen(game->map.grid[0]);
	free(new_map);
}

/** Appends a new line of the map file to the map.
 * 
 * @param new_map Pointer to the new_map string.
 * @param game Pointer to the game struct.
 */
static char	*ft_append_line_to_map(char *new_map, char *line, t_game *game)
{
	char	*result;

	result = ft_strjoin(new_map, line);
	if (result == NULL)
		ft_err_msg_exit("Error\nMalloc failure", game);
	free(new_map);
	return (result);
}

/** Checks for empty lines at the beginning, end and middle of the map file.
 * 
 * @param new_map Pointer to the new_map string.
 * @param game Pointer to the game struct.
 * 
 * This needs to be called before using ft_split() to create the map because
 * ft_split ignores all newlines. Hence why it's not located with the other
 * parse map functions.
 */
static void	empty_line_check(char *new_map, t_game *game)
{
	int	i;

	i = 0;
	if (new_map[0] == '\n')
	{
		free(new_map);
		ft_err_msg_exit("Invalid map. "
			"File starts with an empty line.", game);
	}
	else if (new_map[ft_strlen(new_map) - 1] == '\n')
	{
		free (new_map);
		ft_err_msg_exit("Invalid map. "
			"File ends in an empty line.", game);
	}
	while (new_map[i + 1])
	{
		if (new_map[i] == '\n' && new_map[i + 1] == '\n')
		{
			free(new_map);
			ft_err_msg_exit("Invalid map. "
				"File has an empty line in the middle.", game);
		}
		i++;
	}
}
