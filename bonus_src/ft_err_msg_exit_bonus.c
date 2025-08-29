/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_msg_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:40:10 by tpirinen          #+#    #+#             */
/*   Updated: 2025/08/29 14:16:39 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong_bonus.h"

/**
 * Frees all memory, writes the given error message, exits.
 *
 * @param err_msg message to write to stderr
 * @param game struct being freed
 * @return exits with error code 1
 */
void	ft_err_msg_exit(char *err_msg, t_game *game)
{
	ft_free_all(game);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err_msg, 2);
	exit(1);
}
