/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 04:40:41 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/16 18:00:28 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	**g_mlx(void)
{
	static void	*mlx;

	if (!mlx)
		mlx = mlx_init();
	return (&mlx);
}

void	**g_window(void)
{
	static void *mlx_win;

	if (!mlx_win)
		mlx_win = mlx_new_window(*g_mlx(), get_map_info()->win_w * CELL_W, get_map_info()->win_h * CELL_H, "CUBE3D");
	return (&mlx_win);
}