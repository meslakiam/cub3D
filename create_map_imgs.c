/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_imgs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:31:57 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 13:44:04 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	my_mlx_get_pixel_color(t_data *data, int x, int y)
{
    int *dst;

    dst = (int *)(data->addr + (y * data->line_length) + (x * (data->bits_per_pixel / 8)));
    return (*dst);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length) + (x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

t_data * get_wall_img()
{
    static t_data *wall_img;
    int x;
    int y;

    y = 0;
    if (!wall_img)
    {
        wall_img = ft_calloc(1, sizeof(t_data));
        wall_img->img = mlx_new_image(*g_mlx(), CELL_W, CELL_H);
        wall_img->addr = mlx_get_data_addr(wall_img->img, &wall_img->bits_per_pixel, &wall_img->line_length, &wall_img->endian);
        wall_img->img_height = CELL_H;
        wall_img->img_width = CELL_W;
        while (y < CELL_H - 1)
        {
            x = 0;
            while (x < CELL_W - 1)
            {
                my_mlx_pixel_put(wall_img, x, y, 0x004b4453);
                x++;
            }
            y++;
        }
    }
    return (wall_img);
}

t_data * get_floor_img()
{
    static t_data *floor_img;
    int x;
    int y;

    x = 0;
    y = 0;
    if (!floor_img)
    {
        floor_img = ft_calloc(1, sizeof(t_data));
        floor_img->img = mlx_new_image(*g_mlx(), CELL_W, CELL_H);
        floor_img->addr = mlx_get_data_addr(floor_img->img, &floor_img->bits_per_pixel, &floor_img->line_length, &floor_img->endian);
        floor_img->img_height = CELL_H;
        floor_img->img_width = CELL_W;
        while (y < CELL_H - 1)
        {
            x = 0;
            while (x < CELL_W - 1)
            {
                my_mlx_pixel_put(floor_img, x, y, 0x00b0a8b9);
                x++;
            }
            y++;
        }
    }
    return (floor_img);
}


// t_data get_palyer_pos_img(double angle)
// {
//     static t_data *player_pos_img;
//     t_data n_player_pos_img;
//     int x;
//     int y;
//     double new_x;
//     double new_y;

//     y = 0;
//     if (!player_pos_img)
//     {
//         player_pos_img = ft_calloc(1, sizeof(t_data));
//         player_pos_img->img = mlx_xpm_file_to_image(*g_mlx(), "cube3d_img/palyer_pos/player_pos.xpm", &player_pos_img->img_width,  &player_pos_img->img_height);
//         player_pos_img->addr = mlx_get_data_addr(player_pos_img->img, &player_pos_img->bits_per_pixel, &player_pos_img->line_length, &player_pos_img->endian);
//     }
//     n_player_pos_img.img = mlx_new_image(*g_mlx(), CELL_W, CELL_H);
//     n_player_pos_img.addr = mlx_get_data_addr(n_player_pos_img.img, &n_player_pos_img.bits_per_pixel, &n_player_pos_img.line_length, &n_player_pos_img.endian);
//     while (y < CELL_H)
//     {
//         x = 0;
//         while (x < CELL_W)
//         {
//             new_x = (double)(x - (CELL_W / 2)) * cos(angle) - (double)(y - (CELL_H / 2)) * sin(angle) + (CELL_H / 2);
//             new_y = (double)(x - (CELL_W / 2)) * sin(angle) + (double)(y - (CELL_H / 2)) * cos(angle) + (CELL_H / 2);
//            if (new_x >= 0 && new_x < CELL_W * 3 && new_y >= 0 && new_y < CELL_H * 3)
//                 my_mlx_pixel_put(&n_player_pos_img, (int)new_x + 1, (int)new_y + 1, my_mlx_get_pixel_color(player_pos_img, x, y));
//             x++;
//         }
//         y++;
//     }
//     return (n_player_pos_img);
// }

