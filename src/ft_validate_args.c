/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:25:01 by tpirinen          #+#    #+#             */
/*   Updated: 2025/08/26 19:08:40 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsolong.h"

/** Checks for errors regarding argument count and file format.
 * 
 * @param game Pointer to the game struct.
 */
void	ft_validate_args(int ac, char **av, t_game *game)
{
	char	*ptr_to_file_format;

	(void)game;
	if (ac > 2)
	{
		ft_err_msg_exit("Too many arguments. "
			"You should include a single map file (.ber)\n", game);
	}
	if (ac < 2)
	{
		write(2, "Missing a map file (.ber)\n", 26);
		exit(1);
	}
	ptr_to_file_format = ft_strrchr(av[1], '.');
	if (!ptr_to_file_format || ft_strncmp(ptr_to_file_format, ".ber\0", 5) != 0)
	{
		write(2, "The map file must be of type .ber\n", 34);
		exit(1);
	}
}
