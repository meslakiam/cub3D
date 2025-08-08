/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:23:56 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/07 13:14:53 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void fill_data(void)
{
	t_global *data;

	data = v_global();
    data->win_img = ft_malloc(sizeof(t_data));
     data->map_img = ft_malloc(sizeof(t_data));
	// data->win_width = get_map_info()->win_w * TILESIZE;
	// data->win_height = get_map_info()->win_h * TILESIZE;
    data->win_height = 1080;
    data->win_width = 1920;

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->win_width, data->win_height, "CUBE3D");
    data->win_img->img_width = data->win_width;
    data->win_img->img_height = data->win_height;
    
    data->map_img->img_width = get_map_info()->win_w * TILESIZE;
    data->map_img->img_height = get_map_info()->win_h * TILESIZE;
    
	data->win_img->img = mlx_new_image(data->mlx, data->win_img->img_width, data->win_img->img_height);
	data->win_img->addr = mlx_get_data_addr(data->win_img->img, &data->win_img->bits_per_pixel, &data->win_img->line_length, &data->win_img->endian);
    
    data->map_img->img = mlx_new_image(data->mlx, data->map_img->img_width, data->map_img->img_height);
	data->map_img->addr = mlx_get_data_addr(data->map_img->img, &data->map_img->bits_per_pixel, &data->map_img->line_length, &data->map_img->endian);
}

int main(int argc, char *argv[])
{

    if (argc != 2)
        write(2, "Error\n ---> The Map Args Not Valid\n", 35);
    else
    {
        check_map(argv[1]);
        fill_data();
        // draw_map();
        // t_data dd;
        // dd.img = mlx_xpm_file_to_image(v_global()->mlx, "x.xpm", &dd.img_width, &dd.img_height);
        // dd.addr = mlx_get_data_addr(dd.img, &dd.bits_per_pixel, &dd.line_length, &dd.endian);
        // t_data *new_img = mlx_expand_img(&dd, 1920, 1080);
        // mlx_put_image_to_window(v_global()->mlx, v_global()->mlx_win, new_img->img, 0, 0);
        
        mlx_hook(v_global()->mlx_win, 2, 1L << 0, key_press, NULL);
        mlx_hook(v_global()->mlx_win, 3, 1L << 1, key_release, NULL);
        mlx_loop_hook(v_global()->mlx, move_the_player, NULL);
        mlx_loop(v_global()->mlx);
    }
    return 0;
}
