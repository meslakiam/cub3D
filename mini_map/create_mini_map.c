/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 00:24:22 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/08 23:02:06 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int get_mini_map_color(double x, double y)
{
    int col, (row);
    char map_cor;

    col = y / TILESIZE;
    row = x / TILESIZE;
    if (x < 0 || y < 0 || col > get_map_info()->win_h || row > ft_strlen(get_final_map(0, 0)[col]) - 1)
        return (0);
    if (col * TILESIZE == (int)y || row * TILESIZE == (int)x)
        return (0);
    map_cor = get_final_map(0, 0)[col][row];
    if (map_cor == '1')
        return (WALL_COLOR);
    if (ft_strchr("0NSWE", map_cor))
        return (FLOOR_COLOR);
    else
        return (0);
}

void draw_mini_map()
{
    int i ,(j), (x), (y), (color);

    y = -MINI_MAP_R;
    i = 0;
    while (y <= MINI_MAP_R)
    {
        x = -MINI_MAP_R;
        j = 0;
        while (x <= MINI_MAP_R)
        {
            if (x * x + y * y <= MINI_MAP_R * MINI_MAP_R)
            {
                color = get_mini_map_color(v_player()->p_x + x, v_player()->p_y + y);
                if (x * x + y * y >= (MINI_MAP_R - 3) * (MINI_MAP_R - 3))
                    my_mlx_pixel_put(v_global()->win_img, MINI_MAP_MARGIN + j,  MINI_MAP_MARGIN + i, 0xFFFFFF);
                else
                    my_mlx_pixel_put(v_global()->win_img, MINI_MAP_MARGIN + j,  MINI_MAP_MARGIN + i, color);
            }
            x++;
            j++;
        }
        y++;
        i++;
    }
    draw_circle(MINI_MAP_MARGIN + MINI_MAP_R, MINI_MAP_MARGIN + MINI_MAP_R, RADIUS, 0x00FF0000);
}

//   int y = -radius;
//     int x;

    
//     while (y <= radius)
//     {
//         x = -radius;
//         while (x <= radius)
//         {
//             if (x * x + y * y <= radius * radius)
//                 draw_pixel((int)round(center_y) + y, (int)round(center_x) + x, color);
//             x++;
//         }
//         y++;
//     }
// }