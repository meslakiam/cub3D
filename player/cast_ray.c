/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:57:51 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/30 01:19:05 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
// # include "../cube3d.h"
double angle2;
double distance(double x2, double y2)
{
    double  dx;
    double  dy;

    dx = x2 - v_player()->p_x;
    dy = y2 - v_player()->p_y;    
    return sqrt((dx * dx) + (dy * dy));
}

void    get_vertical_x_hit(double   rad, double *vert_x, double *x_step_v)
{
    if (cos(rad) > 0)
    {
        *vert_x = floor(v_player()->p_x / TILESIZE) * TILESIZE + TILESIZE;
        *x_step_v = TILESIZE;
    }
    else
    {
        *vert_x = floor(v_player()->p_x / TILESIZE) * TILESIZE - 1;
        *x_step_v = -TILESIZE;
    }
}

void  get_vertical_y_hit(double   rad, double *vert_x, double *vert_y, double *y_step_v)
{
    *vert_y = v_player()->p_y + (*vert_x - v_player()->p_x) * tan(rad);

    *y_step_v = fabs(TILESIZE * tan(rad));
    if (sin(rad) < 0)
        *y_step_v *= -1;
}

void find_vertical_hit(double *hit_x, double *hit_y, double rad)
{
    double vert_x, vert_y;
    double x_step_v, y_step_v;

    get_vertical_x_hit(rad, &vert_x, &x_step_v);
    get_vertical_y_hit(rad, &vert_x, &vert_y, &y_step_v);

    while (1)
    {
        int map_x, left_x, right_x;
        if (cos(rad) > 0)
        {
            map_x = vert_x / TILESIZE;
            // left_x = (vert_x + 0.1) / TILESIZE;
            // right_x = (vert_x - 0.1) / TILESIZE;
        }
        else
        {
            map_x = (vert_x - 1) / TILESIZE;
            // left_x = (vert_x - 0.1) / TILESIZE;
            // right_x = (vert_x - 0.1) / TILESIZE;
        }
        int map_y, left_y, right_y; 
        map_y = vert_y / TILESIZE;
        // left_y = (vert_y + 0.1) / TILESIZE;
        // right_y = (vert_y - 0.1) / TILESIZE;

        if (is_wall(map_x, map_y))
            break;
        // else if(is_wall(map_x , left_y))
        //     break;
        // else if (is_wall(right_x, map_y))
        //     break;
        vert_x += x_step_v;
        vert_y += y_step_v;
    }

    *hit_x = vert_x;
    *hit_y = vert_y;
}

void    get_horizontal_y_hit(double  rad, double *hor_y, double  *y_step_h)
{
    if (sin(rad) > 0)
    {
        *hor_y = floor(v_player()->p_y / TILESIZE) * TILESIZE + TILESIZE;
        *y_step_h = TILESIZE;
    }
    else
    {
        *hor_y = floor(v_player()->p_y / TILESIZE) * TILESIZE - 0.0001;
        *y_step_h = -TILESIZE;
    }
}

void    get_horizontal_x_hit(double  rad, double *hor_y, double *hor_x, double  *x_step_h)
{
    *hor_x = v_player()->p_x + (*hor_y - v_player()->p_y) / tan(rad);

    *x_step_h = fabs(TILESIZE / tan(rad));
    if (cos(rad) < 0)
        *x_step_h *= -1;
}

void find_horizontal_hit(double *hit_x, double *hit_y, double rad)
{
    double hor_x, hor_y;
    double x_step_h, y_step_h;

    get_horizontal_y_hit(rad, &hor_y, &y_step_h);
    get_horizontal_x_hit(rad, &hor_y, &hor_x, &x_step_h);

    while (1)
    {
        int map_x, left_x, right_x;
        int map_y, left_y, right_y;
    
        
        map_x = hor_x / TILESIZE;
        // left_x = (hor_x + 0.1) / TILESIZE;
        // right_x = (hor_x - 0.1) / TILESIZE;
        if (sin(rad) > 0)
        {
            map_y = hor_y / TILESIZE;
            // left_y = (hor_y + 0.1) / TILESIZE;
            // right_y = (hor_y - 0.1) / TILESIZE;
        }
        else
        {
            map_y = (hor_y - 1) / TILESIZE;
            // left_y = (hor_y - 0.1) / TILESIZE;
            // right_y = (hor_y - 0.1) / TILESIZE;
        }
        if (is_wall(map_x, map_y))
            break;
        // else if (is_wall(map_x, right_y))
        //     break;
        // else if (is_wall(left_x, map_y))
        //     break;
        
        hor_x += x_step_h;
        hor_y += y_step_h;
    }
    *hit_x = hor_x;
    *hit_y = hor_y;
}



void cast_ray(double angle)
{
    double vx, vy;
    double hx, hy;
    double radian;

    angle2 = angle;
    radian = angle * (M_PI / 180.0);

    if (fabs(cos(radian)) == 0)
        radian += 0.000000001;

    find_vertical_hit(&vx, &vy, radian);
    find_horizontal_hit(&hx, &hy, radian);

    double dist_vert = distance(vx, vy);
    double dist_hor = distance(hx, hy);

    v_player()->was_hit_vertical = (dist_vert < dist_hor);
    if (dist_vert < dist_hor)
    {
        v_player()->end_p_x = vx;
        v_player()->end_p_y = vy;
    }
    else
    {
        v_player()->end_p_x = hx;
        v_player()->end_p_y = hy;
    }
}
