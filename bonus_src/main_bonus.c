/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:19:20 by tpirinen          #+#    #+#             */
/*   Updated: 2025/08/29 15:14:42 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong_bonus.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(game));
	ft_validate_args(ac, av, &game);
	ft_init_map(&game, av[1]);
	ft_parse_map(&game);
	ft_init_mlx(&game);
	ft_init_sprites(&game);
	mlx_hook(game.window, KeyPress, KeyPressMask, ft_handle_input, &game);
	mlx_hook(game.window, DestroyNotify, ButtonPressMask, ft_close_game, &game);
	mlx_hook(game.window, Expose, ExposureMask, ft_render_game, &game);
	mlx_loop(game.mlx);
	ft_free_all(&game);
}
