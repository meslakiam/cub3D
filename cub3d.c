/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:23:56 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/19 22:20:07 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void fill_data(void)
{
	t_global *data;

	data = v_global();
    data->win_img = ft_malloc(sizeof(t_data));
	data->win_width = get_map_info()->win_w * TILESIZE;
	data->win_height = get_map_info()->win_h * TILESIZE;

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->win_width, data->win_height, "Map Draw");
	data->win_img->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->win_img->addr = mlx_get_data_addr(data->win_img->img, &data->win_img->bits_per_pixel, &data->win_img->line_length, &data->win_img->endian);
}

int main(int argc, char *argv[])
{

    if (argc != 2)
        write(2, "Error\n ---> The Map Args Not Valid\n", 35);
    else
    {
        check_map(argv[1]);
        fill_data();
        
        draw_map();
        mlx_hook(v_global()->mlx_win, 2, 1L << 0, key_press, NULL);
        mlx_hook(v_global()->mlx_win, 3, 1L << 1, key_release, NULL);
        mlx_loop_hook(v_global()->mlx, move_the_player, NULL);
        mlx_loop(v_global()->mlx);
    }
    return 0;
}
