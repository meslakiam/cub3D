/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:23:56 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/16 15:55:05 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void fill_data(void)
{
	t_data *data;

	data = v_data();
	data->win_width = v_map()->raw * TILESIZE;
	data->win_height = v_map()->col * TILESIZE;

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->win_width, data->win_height, "Map Draw");
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}

int main(int argc, char const *argv[])
{
    // parsing();
    fill_data();
    draw_map();
    mlx_hook(v_data()->mlx_win, 2, 1L << 0, key_press, NULL);
    mlx_hook(v_data()->mlx_win, 3, 1L << 1, key_release, NULL);
    mlx_loop_hook(v_data()->mlx, move_the_player, NULL);
    mlx_loop(v_data()->mlx);
    return 0;
}
