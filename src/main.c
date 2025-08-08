/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:19:20 by tpirinen          #+#    #+#             */
/*   Updated: 2025/08/08 15:08:04 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libsolong.h"

int	main()
{
	void	*mlx;
	void	*mlx_win;
	
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world");
	mlx_loop(mlx);



}
