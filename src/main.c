/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:19:20 by tpirinen          #+#    #+#             */
/*   Updated: 2025/08/19 15:28:01 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libsolong.h"

int	handle_input(int keysym, t_so_long *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("key %d (ESC) was pressed. Exiting...\n", keysym);
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
		mlx_destroy_display(data->mlx_connection);
		free(data->mlx_connection);
		exit(1);
	}
	ft_printf("pressed the %d key\n\n", keysym);
	return (0);
}

int	main(int ac, char **av)
{
	t_so_long	data;

	(void)ac;
	(void)av;
	data.mlx_connection = mlx_init();
	if (data.mlx_connection == NULL)
		return (1);
	data.mlx_window = mlx_new_window(
			data.mlx_connection, WIDTH, HEIGHT, "so_long");
	if (data.mlx_window == NULL)
	{
		mlx_destroy_display(data.mlx_connection);
		free(data.mlx_connection);
		return (1);
	}
	mlx_key_hook(data.mlx_window, handle_input, &data);

	mlx_loop(data.mlx_connection);

	mlx_put_image_to_window(data.mlx_connection, data.mlx_window, );
	
	mlx_destroy_window(data.mlx_connection, data.mlx_window);
	mlx_destroy_display(data.mlx_connection);
	free(data.mlx_connection);
}
