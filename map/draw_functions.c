/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:35:48 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/05 15:57:03 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void    draw_pixel(int y, int x, int color)
{
    t_data  *data;
    char *tmp;

    data = v_global()->map_img;
    if (x < 0 || y < 0 || x >= get_map_info()->win_w * TILESIZE || y >= get_map_info()->win_h * TILESIZE)
        return;
    tmp = data->addr + ((y * data->line_length) + (x * (data->bits_per_pixel / 8)));
    *(unsigned int *)tmp = color;
}

void    draw_ray_pixel(int y, int x, int color)
{
    t_data  *data;
    char *tmp;
    char *ch;
    double dis;
    double opacity;

    dis = distance(x, y);
    if (dis < 10)
        opacity = 1;
    else
        opacity = 10 / dis;
    data = v_global()->map_img;
    if (x < 0 || y < 0 || x >= get_map_info()->win_w * TILESIZE || y >= get_map_info()->win_h * TILESIZE)
        return;
    tmp = data->addr + ((y * data->line_length) + (x * (data->bits_per_pixel / 8)));
    // color = blend_colors(*(unsigned int *)tmp, color, opacity);
    *(unsigned int *)tmp = color;
}

void    draw_square(int y, int x, int color)
{
    int start_y;
    int start_x;

    start_y = y;
    start_x = x;
    while (y < start_y + (TILESIZE - 1))
    {
        x = start_x;
        while (x < start_x + (TILESIZE - 1))
        {
            draw_pixel(y, x, color);
            x++;
        }
        if(x == start_x + (TILESIZE - 1))
            draw_pixel(y, x, 0x000000);
        y++;
    }
    if(y == start_y + (TILESIZE - 1))
    {
        x = start_x;
        while (x < start_x + (TILESIZE))
        {
            draw_pixel(y, x, 0x0000000);
            x++;
        }
    }   
}

// void    draw_square(int y, int x, int color)
// {
//     int start_y;
//     int start_x;

//     start_y = y;
//     start_x = x;
//     while (y < start_y + TILESIZE)
//     {
//         x = start_x;
//         while (x < start_x + TILESIZE)
//         {
//             draw_pixel(y, x, color);
//             x++;
//         }
//         y++;
//     }
    
// }

void    draw_circle(double center_y, double center_x, int radius, int color)
{
    int y = -radius;
    int x;

    
    while (y <= radius)
    {
        x = -radius;
        while (x <= radius)
        {
            if (x * x + y * y <= radius * radius) // inside the circle
                draw_pixel((int)round(center_y) + y, (int)round(center_x) + x, color);
            x++;
        }
        y++;
    }
}

double draw_line(int x0, int y0, int x1, int y1, int color)
{
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;
    int x, y;

    x = x0;
    y = y0;
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);

    if (x0 < x1)
        sx = 1;
    else
        sx = -1;
    
    if (y0 < y1)
        sy = 1;
    else
        sy = -1;
    err = dx - dy;

    while (1)
    {
        draw_ray_pixel(y0, x0, color);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
    return 0;
}
