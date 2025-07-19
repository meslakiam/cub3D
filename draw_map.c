/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:55:24 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 15:27:50 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"

void mlx_merge_img(int x, int y, t_data *src, t_data *dst)
{
    int origin_x;
    int i;
    int j;
    int color;

    origin_x = x;
    j = 0;
    i = 0;
    printf ("w %d, h %d\n", src->img_width, src->img_height);
    while (i < src->img_height)
    {
        x = origin_x;
        j = 0;
        while (j <  src->img_width)
        {
            color =  my_mlx_get_pixel_color(src, j, i);
            if (color != 0)
                my_mlx_pixel_put(dst, x, y, color);
            j++;
            x++;
        }
        i++;
        y++;
    }
}
void draw_map()
{
    t_data  *map_img = NULL;
    char    **map;
    int     x;
    int     y;

    y = 0;
    map = get_final_map(0, 0);
    if (!map_img)
    {
        map_img = ft_calloc(1, sizeof(t_data));
        map_img->img = mlx_new_image(*g_mlx(), CELL_W * get_map_info()->win_w, CELL_H *  get_map_info()->win_h);
        map_img->addr = mlx_get_data_addr(map_img->img, &map_img->bits_per_pixel, &map_img->line_length, &map_img->endian);
    }
    
    while (map[y])
    {
        x = 0;
        while(map[y][x])
        {
            if (map[y][x] == '0')
                mlx_merge_img(x * CELL_W, y * CELL_H, get_floor_img(), map_img);
            else if (ft_strrchr("ENWS", map[y][x]))
            {
                mlx_merge_img(x * CELL_W, y * CELL_H, get_floor_img(), map_img);
                mlx_merge_img(x * CELL_W, y * CELL_H, get_pos_img(map[y][x], 1), map_img);
            }
            else if (map[y][x] == '1')
                mlx_merge_img(x * CELL_W, y * CELL_H, get_wall_img(), map_img);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(*g_mlx(), *g_window(), map_img->img, 0, 0);
   
}


// if (map[y][x] == '0' || map[y][x] == ' ')
//                 mlx_put_image_to_window(*g_mlx(), *g_window(), get_floor_img()->img, x * CELL_W, y * CELL_H);
//             else if (ft_strrchr("ENWS", map[y][x]))
//             {
//                 player_x = x * CELL_W;
//                 player_y = y * CELL_H;
//                 mlx_put_image_to_window(*g_mlx(), *g_window(), get_pos_imglst(map[y][x], 1)->img, player_x, player_y);
//             }
//             else
//                 mlx_put_image_to_window(*g_mlx(), *g_window(), get_wall_img()->img, x * CELL_W, y * CELL_H);