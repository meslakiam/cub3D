/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:18:26 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/09 09:48:36 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_square(int y, int x, int color)
{
    int start_y;
    int start_x;

    start_y = y;
    start_x = x;
    while (y < start_y + PIXEL)
    {
        x = start_x;
        while (x < start_x + PIXEL)
        {
            draw_pixel(y, x, color);
            x++;
        }
        y++;
    }
    
}
//0.05 0.99   2 / 2 = 0.99999999999994       = 0
void draw_filled_circle(double center_y, double center_x, int radius, int color)
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

// void draw_line(int x0, int y0, int x1, int y1, int color)
// {
//     int dx;
//     int dy;
//     int steps;
//     float x_inc;
//     float y_inc;
//     float x;
//     float y;
//     int i;

//     dx = x1 - x0;
//     dy = y1 - y0;

//     if (abs(dx) > abs(dy))
//         steps = abs(dx);
//     else
//         steps = abs(dy);

//     x_inc = dx / (float)steps;
//     y_inc = dy / (float)steps;

//     x = x0;
//     y = y0;

//     i = 0;
//     while (i <= steps)
//     {
//         draw_pixel((int)(y + 0.5), (int)(x + 0.5), color);
//         x += x_inc;
//         y += y_inc;
//         i++;
//     }
// }

// void draw_line(int x0, int y0, int x1, int y1, int color)
// {
//     int dx = x1 - x0;
//     int dy = y1 - y0;
//     double stepx = 0;
//     double stepy = 0;
//     int step = fmax(abs(dx), abs(dy));
    
//     if (step)
//     {
//          stepx = dx / step;
//          stepy = dy / step;
//     }
//     int  i = 0;
//     while (i <= step + 1)
//     {
//         draw_pixel(round(y0 + i * stepy), round(x0 + i * stepx), color);
//         i++;
//     }
// }

// void draw_line(int x0, int y0, int x1, int y1, int color)
// {
//     int dx;
//     int dy;
//     int sx;
//     int sy;
//     int err;
//     int e2;
//     int c;
//     int m;

//     m = (y0 - y1)/(x0 - x1);


// }

int is_wall2(int y, int x)
{
    int row;
    int col;

    row = x / PIXEL;
    col = y / PIXEL;
    if (v_map()->map[col][row] == '1')
        return 1;
    return 0;
}

double distance(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
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
        if (is_wall2(y0, x0))
            break;
        draw_pixel(y0, x0, color);
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
    return distance(x, y, x0, y0);
}


void    draw_pixel(int y, int x, int color)
{
    t_data  *data;
    char *tmp;

    data = v_data();
    if (x < 0 || y < 0 || x >= data->win_width || y >= data->win_height)
        return;
    tmp = data->addr + ((y * data->line_length) + (x * (data->bits_per_pixel / 8)));
    *(unsigned int *)tmp = color;
}
