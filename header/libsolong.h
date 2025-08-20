/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsolong.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:44:52 by tpirinen          #+#    #+#             */
/*   Updated: 2025/08/19 15:10:25 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSOLONG_H
# define LIBSOLONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <X11/keysym.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_so_long
{
	void	*mlx_connection;
	void	*mlx_window;
}	t_so_long;

#endif