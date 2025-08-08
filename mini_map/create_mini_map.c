/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 00:24:22 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/07 13:12:19 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int get_mini_map_color(int x, int y)
{
    if (get_final_map(0, 0)[y / TILESIZE][x / TILESIZE] == '1')
        return (WALL_COLOR);
    else if (get_final_map(0, 0)[y / TILESIZE][x / TILESIZE] == ('0' || ' '))
        return (FLOOR_COLOR);
    else
        return (0);
}

void draw_mini_map()
{
    int i ,(j), (x), (y);

    y = -MINI_MAP_R;
    i = 0;
    while (y <= MINI_MAP_R)
    {
        x = -MINI_MAP_R;
        j = 0;
        while (x <= MINI_MAP_R)
        {
            if (x * x + y * y <= MINI_MAP_R * MINI_MAP_R)
                my_mlx_pixel_put(v_global()->win_img, 50 + j,  50 + i, get_mini_map_color(v_player()->p_x + x, v_player()->p_y + y));
            x++;
            j++;
        }
        y++;
        i++;
    }
    draw_circle(50 + v_player()->p_y, 50 + v_player()->p_x, 5, 0x00FF0000);
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